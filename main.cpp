#include<iostream>
#include<fstream>
//#include<conio.h>
//#include<stdlib.h>
//#include<stdio.h>
using namespace std;
class shopping
{
    private:int code,key;
            float price;
            float dis;
            //char name[80];
            string name;
    public: void menu();
            void administrator();
            void buyer();
           void add();
           void edit();
           void del();
           void list();
           void receipt();
           void preprotection();
            
};
void shopping::preprotection()
{
    string id,password;
    cout<<"Enter user name:- ";
    cin>>id;
    cout<<"Enter password:- ";
    cin>>password;
    string n,p;
    fstream file("passkey.txt",ios::in);
    file>>n>>p;
    while(!file.eof())
    {
        if(n==id)
        {
            administrator();
            return ;
        }
        file>>n>>p;
    }
    cout<<"Invalid Credentials\n\n";
}
void shopping::menu()
{
    int choice;
    //char email[80],password[80];
    string email,password;
    cout<<"\t\t\t\t******************************\n";
    cout<<"\t\t\t\t                              \n";
    cout<<"\t\t\t\t      McDonald's main menu    \n";
    cout<<"\t\t\t\t                              \n";
    cout<<"\t\t\t\t******************************\n";
    cout<<"\t\t\t\t |   1.Administrator      |\n ";
    cout<<"\t\t\t\t |                        |\n ";
    cout<<"\t\t\t\t |   2.Buyer              |\n ";
    cout<<"\t\t\t\t |                        |\n ";
    cout<<"\t\t\t\t |   3.exit               |\n ";
    cout<<"\t\t\t\t |                        |\n ";
    cout<<"\n\t\t\t please enter your choice:- ";
    cin>>choice;
    switch(choice)
    {
       case 1:
             preprotection();
             break;
        break;
        case 2: buyer();
                break;
       case 3: exit(0);
                break;
        default: cout<<"please select form the givin options!";
                break;
        
    }
}
void shopping::administrator()
{
    int choice;
    char ch;
    do
    {
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t |    1]Add the product       |";
    cout<<"\n\t\t\t |                            |  ";
    cout<<"\n\t\t\t |    2]Modify the product    |";
    cout<<"\n\t\t\t |                            | ";
    cout<<"\n\t\t\t |    3]Delete the product    |";
    cout<<"\n\t\t\t |                            |  ";
    cout<<"\n\t\t\t |    4]Back to main menu     |";
    cout<<"\n\t\t\t |                            |  ";
    cout<<"\n\n\t Please enter your choice:- ";
    cin>>choice;
    switch(choice)
    {
        case 1:add();
               break;
        case 2:edit();
               break;
        case 3:del();
               break;
        case 4:menu();
               break;  
        default: cout<<"Invalid choice!/n";
        
    }
    cout<<"do u want to continue:";
    cin>>ch;
}while(ch=='y'||ch=='Y');
}
void shopping::buyer()
{
    int choice;
    char ch;
    do
    {
    cout<<"\n\n\n\t\t\t buyer     ";
    cout<<"\n\t\t\t |    1]buy product       |";
    cout<<"\n\t\t\t |                        |  ";
    cout<<"\n\t\t\t |    2]go back           |";
    cout<<"\n\t\t\t |                        | ";
    cout<<"\n\n\t Please enter your choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:receipt();
               break;
        case 2:menu();
               break;

        default: cout<<"Invalid choice!/n";
        
    }
    cout<<"\n\n\t\tdo u want to continue:";
    cin>>ch;
}while(ch=='y'||ch=='Y');
}
void shopping::add()
{
    m:
    fstream data;
    fstream data1;
    int c;
    int token=0;
    float p,d;
    //char n[80];
    string n;
    cout<<"\n\n\t\t\t Add  product:";
    cout<<"\n\n\t Enter the code of  product:- "; 
    cin>>code;
    cout<<"\n\n\t Enter the name of  product:- "; 
    cin>>name;
    cout<<"\n\n\t Enter the price of  product:- "; 
    cin>>price;
    cout<<"\n\n\t Discount on  product:- "; 
    cin>>dis;
    
    data.open("database.txt",ios::in);
    
    if(!data)
    {
        data1.open("database.txt",ios::out);
        data1<<" "<<code<<" "<<name<<" "<<price<<" "<<dis<<"\n";
        data1.close();
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==code)
            {
                token ++;
            }
             data>>c>>n>>p>>d;
        }
        data.close();
        if(token==1)
        {
            goto m;
        }
        else
        {
             data1.open("database.txt",ios::app|ios::out);
            data1<<" "<<code<<" "<<name<<" "<<price<<" "<<dis<<"\n";
            data1.close();
        
        }
    }
    cout<<"\n\n\t\t Record inserted\n\n";
}
void shopping::edit()
{
    m:
    fstream data,data1;
    int key,c;
    int token=0;
    float p,d;
    //char n[80];
    string n;
    cout<<"\n\n\t\t\t Modify the record:";
    cout<<"\n\n\t Product code:"; 
    cin>>key;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n File dosen't exit!\n";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>code>>name>>price>>dis;
        while(!data.eof())
        {
            if(key==code)
            {
               cout<<"\n\t\t product  code:";
               cin>>c;
               cout<<"\n\t\t Name of the product:";
               cin>>n;
               cout<<"\n\t\t Price of product:";
               cin>>p;
               cout<<"\n\t\t Discount on product:";
               cin>>d;
               data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
               cout<<"\n\n\t\t Record inserted\n\n";
               token++;
            }
            else
            {
             data1<<" "<<code<<" "<<name<<" "<<price<<" "<<dis<<"\n";    
            
            }
            data>>code>>name>>price>>dis;
        }
        data.close();
        data1.close();
    }
    remove("database.txt");
    rename("database1.txt","database.txt");
    if(token==0)
    {
        cout<<"\n\n Record not found!\n\n";
    }
    
}
void shopping::del()
{
   // m:
    fstream data;
    fstream data1;
    int c;
    int token=0;
   // float p,d;
   // char n[80];
    cout<<"\n\n\t\t\t Enter the product code of product to be deleted:- ";
    cin>>key;
    data.open("database.txt",ios::in);
    
    if(!data)
    {
       cout<<"File dosen't exit!";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>code>>name>>price>>dis;
        while(!data.eof())
        {
            if(code==key)
            {
                token ++;
            }
            else
            {
                 data1<<" "<<code<<" "<<name<<" "<<price<<" "<<dis<<"\n";
            }
            data>>code>>name>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
    }
    if(token==0)
    {
      cout<<"\n\n Record not found!\n\n";
    }
    else
    {
        cout<<"\n\n\t Product deleted\n\n";
    }
}
void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|********************************************\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|********************************************\n";
    data>>code>>name>>price>>dis;
    while(!data.eof())
    {
        cout<<code<<"\t\t"<<name<<"\t\t"<<price<<"\n";
        data>>code>>name>>price>>dis;
    }
    data.close();
}
void shopping::receipt()
{
    m:
    fstream data;
    int arrc[80];
    int arrq[80];
    char choice;
    int c=0;
    float amount=0,dis=0,total=0;
    cout<<"\n\n\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
        
    }
    else
    {
        data.close();
        cout<<"\n*******************************\n";
        cout<<"\n|                              |\n";
        cout<<"\n   Please place the order      \n";
        cout<<"\n|                              |\n";
        cout<<"\n*******************************\n";
        do{
            cout<<"\n\n Enter product code:";
            cin>>arrc[c];
            cout<<"\n\n Enter the product quantity:";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code.Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? (if yes plz press y)";
            cin>>choice;
        }while(choice=='y');
    }
    
    cout<<"\n\n\t\t\t*******************RECEIPT**************************\n";
    cout<<"\n Product No\t Product quantity\t Price\t Amount\tAmount with discount\n";
    for(int i=0;i<c;i++)
    {
        data.open("database.txt",ios::in);
        data>>code>>name>>price>>dis;
        while(!data.eof())
        {
            if(code==arrc[i])
            {
                amount=price*arrq[i];
                dis=amount-(amount*dis/100);
                total=total+dis;
                cout<<"\n"<<code<<"\t\t"<<name<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                
            }
            data>>code>>name>>price>>dis;
        }
    }
    data.close();
    cout<<"\n\n*******************************************";
    cout<<"\n Total amount:"<<total;
}
int main()
{
    shopping s;
   // clrscr();
    s.menu();
    return 0;
}




