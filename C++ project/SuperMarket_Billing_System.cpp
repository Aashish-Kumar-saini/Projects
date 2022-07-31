#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;
    public:
        void menu();
        void adminstrator();
        void buyer();
        void add();
        void edit();
        void res();
        void list();
        void reciept();
};
void shopping :: menu()
{

    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t__________________________________________\n";
    cout<<"\t\t\t\t                                          \n";
    cout<<"\t\t\t\t           Supermarket MAIn MEnu          \n";
    cout<<"\t\t\t\t__________________________________________\n";
    cout<<"\t\t\t\t                                          \n";
    cout<<"\t\t\t\t|  1) Administrator      |\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t|  2) Buyer              |\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t|  3) Exit               |\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\n\t\t\t Please select! : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please Login \n";
            cout<<"\t\t\t Enter Email  \n";
            cin>>email;
            cout<<"\t\t\t Password     \n";
            cin>>password;

            if(email=="aashishkumarsaini2000@gmail.com"&&password=="aashish123"||email=="satyamsharma7255@gmail.com" && password=="satyam123")
            {
                adminstrator();
            }
            else{
                cout<<"Invalid email/password";
            }
            break;
    
        case 2:
            buyer();
            break;
        case 3:
            exit(0);
        
        default :
            cout<<"Please select from the given options";
            break;
    }
goto m;

}

void shopping::adminstrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|_____1) Add the product_____|";
    cout<<"\n\t\t\t|____________________________|";
    cout<<"\n\t\t\t|_____2) Modify the product__|";
    cout<<"\n\t\t\t|____________________________|";
    cout<<"\n\t\t\t|_____3) Delete the product__|";
    cout<<"\n\t\t\t|____________________________|";
    cout<<"\n\t\t\t|_____4) Back to main menu___|";

    cout<<"\n\n\t Please enter the choice ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            add();
            break;
        
        case 2:
            edit();
            break;
        
        case 3:
            res();
            break;
        
        case 4:
            menu();
            break;

        default:
        cout<<"Invalid choice!";

    }
goto m;
}

void shopping::buyer()
{
    m:
    int choice;
    cout<<"\t\t\t Buyer \n";
    cout<<"\t\t\t________________\n";
    cout<<"\t\t\t 1) Buy product \n";
    cout<<"\t\t\t          \n";
    cout<<"\t\t\t 2) Go back   \n";
    cout<<"\t\t\t Enter your choice : ";

    cin>>choice;
    switch(choice)
    {
        case 1:
            reciept();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"Invalid choice";

    }
    goto m;
}
void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product in INT ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product ";
    cin>>pname;
    cout<<"\n\n\t Price of the product ";
    cin>>price;
    cout<<"\n\n\t Disocunt on the product ";
    cin>>dis;

    data.open("shopping.txt",ios::in);

    if(!data)
    {
        data.open("shopping.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        if(token==1)
            goto m;
        else{
            data.open("shopping.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
    }
    cout<<"\n\n\t\t Record inserted :";

}

void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code ";
    cin>>pkey;
    data.open("shopping.txt",ios::in);
    if(!data){
        cout<<"\n\nFile does'nt exist! ";
    }
    else{
        data1.open("shopping1.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code : ";
                cin>>c;
                cout<<"\n\t\t Name of the product : ";
                cin>>n;
                cout<<"\n\t\t Price : ";
                cin>>p;
                cout<<"\n\t\t Discount : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\tRecord edited ";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
            
            data.close();
            data1.close();

            remove("shopping.txt");
            if(rename("shopping1.txt","shopping.txt") !=0)
            cout<<"\n\t\t Error!!!..";
            else{
                cout<<"\n\t\t Updated successfully ";
            }

            if(token==0)
            {
                cout<<"\n\n Record not found sorry!";
            }
        
    }
}
void shopping:: res()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delte product";
    cout<<"\n\n\t Product code : ";
    cin>>pkey;
    data.open("shopping.txt",ios::in);
    if(!data)
    {
        cout<<"File doesn't exist";
    }
    else{
        data1.open("shopping1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted succesfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
            
            data.close();
            data1.close();
            remove("shopping.txt");
            if(rename("shopping1.txt","shopping.txt") !=0)
            cout<<"\n\t\t Error!!!..";
            else{
                cout<<"\n\t\t Updated successfully ";
            }
            if(token==0)
            {
                cout<<"\n\n Record not found";
            }
        
    }
}

void shopping :: list()
{
    fstream data;
    data.open("shopping.txt",ios::in);
    cout<<"\n\n|________________________________________\n";
    cout<<"ProNO\t\tName\t\tPrice\n";
    cout<<"\n\n|_________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t"<<pname<<"\t\t"<<price<<endl;
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
void shopping::reciept()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount =0;
    float d=0;
    float total=0;

    cout<<"\n\n\t\t\t RECIPT ";
    data.open("shopping.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }

    else{
        data.close();
        
        list();
        cout<<"\n_______________________________________\n";
        cout<<"\n                                       \n";
        cout<<"\n       Please place the order          \n";
        cout<<"\n                                       \n";
        cout<<"\n_______________________________________\n";
        do
        {
            m:
            cout<<"\n\nEnter Product code : ";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity : ";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code. Please try again";
                    goto m;
                }
            }c++;
            cout<<"\n\n Do you want to buy another product if yes than press y else n ";
            cin>>choice;
        } while (choice =='y');
        
        cout<<"\n\n\t\t\t_________________RECIPT___________________";
        cout<<"\nProduct No.\tProduct Name\t\t product quantity\t\tprice\t\tAmount with discount\n";

        for(int i=0;i<c;i++)
        {
            data.open("shopping.txt",ios :: in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()&&i<100)
            {
                if(pcode==arrc[i])
                {
                    amount =price*arrq[i];
                    d =amount-(amount*dis/100);
                    total=total +d;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<d;
                    
                }
                
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
        }
        
    }
    cout<<"\n\n_____________________________________________________";
    cout<<"\n Total Amount : "<<total;
}

int main()
{
    shopping s;
    s.menu();

}
