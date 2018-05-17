#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<graphics.h>
using namespace std;
void masking();

int k=7,r=0,flag=0;
COORD coord = {0, 0};

void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct date
{int mm,dd,yy;};

ofstream fout;
ifstream fin;

char passwordM[20];

void masking()
{
    for(int i=0;i<20;i++)
        {
            passwordM[i]=NULL;
        }

        char ast;
        int i=0;

         do{
                ast = getch();
                if (ast == 13 || ast == ' ' ){
                    break;
                }
                if(ast==8 && i>0){
                    cout<<"\b";
                    cout<<" ";
                    cout<<"\b";
                    passwordM[i-1]=NULL;
                    i--;
                    continue;
                }
                if(ast!=8){
                    cout<<"*";
                    passwordM[i]=ast;
                    i++;
                }
            }while(ast!=13 || ast!=' ');

}

class Item
{
    int itemno;
    char name[25];
    date d;

public:

    void add()
    {
        cout<<"\n\n\tItem No: ";
        cin>>itemno;
        cout<<"\n\n\tName of the item: ";
        cin>>name;
        //gets(name);
        cout<<"\n\n\tManufacturing Date(dd-mm-yy): ";
        cin>>d.mm>>d.dd>>d.yy;
    }

    void show()
    {
        cout<<"\n\tItem No: ";
        cout<<itemno;
        cout<<"\n\n\tName of the item: ";
        cout<<name;
        cout<<"\n\n\tDate : ";
        cout<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
    }

    void report()
    {
        gotoxy(3,k);
        cout<<itemno;
        gotoxy(13,k);
        puts(name);
    }

    int retno()
    {
        return(itemno);
    }

    ~Item()
    {

    }

};

class Amount: public Item
{
    float price, qty, tax, gross, dis, netamt;

public:

    void add();
    void show();
    void report();
    void calculate();
    void pay();

    float retnetamt()
    {
        return(netamt);
    }

}amt;

void Amount::add()
{
    Item::add();
    cout<<"\n\n\tPrice: ";
    cin>>price;
    cout<<"\n\n\tQuantity: ";
    cin>>qty;
    cout<<"\n\n\tTax percent: ";
    cin>>tax;
    cout<<"\n\n\tDiscount percent: ";
    cin>>dis;
    calculate();
    fout.write((char *)&amt,sizeof(amt));
    fout.close();
}

void Amount::calculate()
{
    gross=price+(price*(tax/100));
    netamt=qty*(gross-(gross*(dis/100)));
}

void Amount::show()
{
    fin.open("itemstore.dat",ios::binary);
    fin.read((char*)&amt,sizeof(amt));
    Item::show();
    cout<<"\n\n\tNet amount: ";
    cout<<netamt;
    fin.close();
}

void Amount::report()
{
    Item::report();
    gotoxy(23,k);
    cout<<price;
    gotoxy(33,k);
    cout<<qty;
    gotoxy(44,k);
    cout<<tax;
    gotoxy(52,k);
    cout<<dis;
    gotoxy(64,k);
    cout<<netamt;
    k=k+1;

    if(k==50)
    {
        gotoxy(25,50);
        cout<<"PRESS ANY KEY TO CONTINUE...";
        getch();
        k=7;
        system("cls");
        gotoxy(30,3);
        cout<<" ITEM DETAILS ";
        gotoxy(3,5);
        cout<<"NUMBER";
        gotoxy(13,5);
        cout<<"NAME";
        gotoxy(23,5);
        cout<<"PRICE";
        gotoxy(33,5);
        cout<<"QUANTITY";
        gotoxy(44,5);
        cout<<"TAX";
        gotoxy(52,5);
        cout<<"DEDUCTION";
        gotoxy(64,5);
        cout<<"NET AMOUNT";
    }
}

void Amount::pay()
{
    show();
    cout<<"\n\n\n\t\t*********************************************";
    cout<<"\n\t\t                 DETAILS                  ";
    cout<<"\n\t\t*********************************************";
    cout<<"\n\n\t\tPRICE                     :"<<price;
    cout<<"\n\n\t\tQUANTITY                  :"<<qty;
    cout<<"\n\t\tTAX PERCENTAGE              :"<<tax;
    cout<<"\n\t\tDISCOUNT PERCENTAGE         :"<<dis;
    cout<<"\n\n\n\t\tNET AMOUNT              :Rs."<<netamt;
    cout<<"\n\t\t*********************************************";
}

class User
{
    string uun, upw, _un, _pw;
    public:
        void userLog()
        {
            fstream f1("user.txt", ios::in);
            f1 >> _un >> _pw;
            B:
            system("CLS");
            gotoxy(53,11);
            cout << "User Login...\n";
            gotoxy(45,12);
            cout<<"--------------------------";
            gotoxy(50,14);
            cout << "Enter User name : ";
            cin >> uun;
            gotoxy(50,15);
            cout << "Enter Password  : ";
            masking();
            if (uun == _un && passwordM == _pw)
            {
                gotoxy(51,18);
                cout << "Login success..."; Sleep(2000);
                cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout<<setprecision(2);
    fstream tmp("temp.dat",ios::binary|ios::out);
    menu:
    system("cls");
    gotoxy(46,9);
    cout<<"    Super Market Billing ";
    gotoxy(46,10);
    cout<<"===========================";
    gotoxy(48,11);
    cout<<"1.Add/Remove/Edit Item";
    gotoxy(48,12);
    cout<<"2.Show Item Details";
    gotoxy(48,13);
    cout<<"3.Exit";
    gotoxy(45,16);
    cout<<"Please Enter Required Option: ";

    int ch,ff;
    float gtotal;
    cin>>ch;

    switch(ch)
    {

    case 1: db:
            system("cls");
            gotoxy(50,9);
            cout<<"    Bill Editor";
            gotoxy(49,10);
            cout<<"=====================";
            gotoxy(49,12);
            cout<<"1.Add Item Details";
            gotoxy(49,13);
            cout<<"2.Edit Item Details";
            gotoxy(49,14);
            cout<<"3.Delete Item Details";
            gotoxy(49,15);
            cout<<"4.Back to Main Menu ";
            gotoxy(50,17);
            cout<<"Enter your choice  ";
            int apc;
            cin>>apc;
            switch(apc)
            {
            case 1: system("cls");
                    fout.open("itemstore.dat",ios::binary|ios::app);
                    amt.add();
                    cout<<"\n\t\t\t\t\tItem Added Successfully!";
                    getch();
                    goto db;

            case 2: system("cls");
                    int ino;
                    flag=0;
                    cout<<"\n\n\tEnter Item Number to be Edited :";
                    cin>>ino;
                    fin.open("itemstore.dat",ios::binary);
                    fout.open("itemstore.dat",ios::binary|ios::app);

                    if(!fin)
                    {
                        cout<<"\n\nFile Not Found...";
                        goto menu;
                    }

                    fin.seekg(0);
                    r=0;
                    while(!fin.eof())
                    {
                        fin.read((char*)&amt,sizeof(amt));

                        if(!fin.eof())
                        {
                            int x=amt.Item::retno();
                            if(x==ino)
                            {
                                flag=1;
                                fout.seekp(r*sizeof(amt));
                                system("cls");
                                cout<<"\n\t\tCurrent Details are\n";
                                amt.show();
                                cout<<"\n\n\t\tEnter New Details\n";
                                amt.add();
                                cout<<"\n\t\tItem Details editted";
                            }
                        }
                        r++;
                    }

                    if(flag==0)
                    {
                        cout<<"\n\t\tItem No does not exist...Please Retry!";
                        getch();
                        goto db;
                    }
                    fin.close();
                    getch();
                    goto db;

            case 3: system("cls");
                    flag=0;
                    cout<<"\n\n\tEnter Item Number to be deleted :";
                    cin>>ino;
                    fin.open("itemstore.dat",ios::binary);
                    if(!fin)
                    {
                        cout<<"\n\nFile Not Found...";
                        goto menu;
                    }
                    fin.seekg(0);

                    while(fin.read((char*)&amt, sizeof(amt)))
                    {
                        int x=amt.Item::retno();
                        if(x!=ino)
                        tmp.write((char*)&amt,sizeof(amt));
                        else
                        {flag=1;}
                    }

                    fin.close();
                    tmp.close();
                    fout.open("itemstore.dat",ios::trunc|ios::binary);
                    fout.seekp(0);
                    tmp.open("temp.dat",ios::binary|ios::in);

                    if(!tmp)
                    {
                        cout<<"Error in File";
                        goto db;
                    }

                    while(tmp.read((char*)&amt,sizeof(amt)))
                    {
                        fout.write((char*)&amt,sizeof(amt));
                    }
                    tmp.close();
                    fout.close();

                    if(flag==1)
                    {
                        cout<<"\n\t\tItem Succesfully Deleted";
                    }

                    else if (flag==0)
                    {
                        cout<<"\n\t\tItem does not Exist! Please Retry";
                    }
                    getch();
                    goto db;

            case 4: goto menu;
                    default: cout<<"\n\n\t\tWrong Choice!!! Retry";
                    getch();
                    goto db;
            }
                    case 2: system("cls");
                            flag=0;
                            int ino;
                            cout<<"\n\n\t\tEnter Item Number :";
                            cin>>ino;
                            fin.open("itemstore.dat",ios::binary);
                            if(!fin)
                            {cout<<"\n\nFile Not Found...\nProgram Terminated!";
                            goto menu;
                            }
                            fin.seekg(0);
                            while(fin.read((char*)&amt,sizeof(amt)))
                            {
                                int x=amt.Item::retno();
                                if(x==ino)
                                {
                                    amt.pay();
                                    flag=1;
                                    break;
                                }
                            }

                            if(flag==0)
                            {
                                cout<<"\n\t\tItem does not exist....Please Retry!";
                            }
                            getch();
                            fin.close();
                            goto menu;

                    case 3: system("cls");
                            gotoxy(38,18);
                            cout<<"ARE YOU SURE, YOU WANT TO Logut (Y/N)?";
                            char yn;
                            cin>>yn;

                            if((yn=='Y')||(yn=='y'))
                            {
                                system("cls");
                                exit(0);
                            }
                            else if((yn=='N')||(yn=='n'))
                            {
                                goto menu;
                            }
                            else
                            {
                                goto menu;
                            }

                   default: cout<<"Wrong Choice....Please Retry!";
                            getch();
                            goto menu;
    }


            }

            else
            {
                gotoxy(36,20);
                cout << "Username / Password Incorrect... Try Again..." ; Sleep(2000); goto B;
            }

        }

};

class Manager
{
    string mun, mpw, _un, _pw;
public :
    void manLog()
    {
        fstream a("admin.txt",ios::in);
        a >> _un >> _pw;
            C:
            system("CLS");
            gotoxy(52,11);
            cout << "Manager Login...\n";
            gotoxy(45,12);
            cout<<"--------------------------";
            gotoxy(50,14);
            cout << "Enter User name : ";
            cin >> mun;
             gotoxy(50,15);
            cout << "Enter Password  : ";
            masking();
            if (mun == _un && passwordM == _pw)
            {
                B:
                gotoxy(51,18);
                cout << "Login success..."; Sleep(2000);
                cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout<<setprecision(2);
    fstream tmp("temp.dat",ios::binary|ios::out);
    menu:
    system("cls");
    gotoxy(48,9);
    cout<<"Super Market Billing ";
    gotoxy(44,10);
    cout<<"===========================";
    gotoxy(49,12);
    cout<<"1.Bill Report";
    gotoxy(49,13);
    cout<<"2.Show Item Details";
    gotoxy(49,14);
    cout<<"3.Exit";
    gotoxy(42,16);
    cout<<"Please Enter Required Option: ";

    int ch,ff;
    float gtotal;
    cin>>ch;

    switch(ch)
    {
        case 1: ss:
                system("cls");
                gotoxy(56,9);
                cout<<"Bill Details";
                gotoxy(54,10);
                cout<<"================";
                gotoxy(53,12);
                cout<<"1.All Items";
                gotoxy(53,13);
                cout<<"2.Back to Main menu";
                gotoxy(48,15);
                cout<<"Please Enter Required Option: ";
                int cho;
                cin>>cho;

                if(cho==1)
                {
                    system("cls");
                    gotoxy(30,3);
                    cout<<" BILL DETAILS ";
                    gotoxy(3,5);
                    cout<<"ITEM NO";
                    gotoxy(13,5);
                    cout<<"NAME";
                    gotoxy(23,5);
                    cout<<"PRICE";
                    gotoxy(33,5);
                    cout<<"QUANTITY";
                    gotoxy(44,5);
                    cout<<"TAX %";
                    gotoxy(52,5);
                    cout<<"DISCOUNT %";
                    gotoxy(64,5);
                    cout<<"NET AMOUNT";
                    fin.open("itemstore.dat",ios::binary);

                    if(!fin)
                    {
                        cout<<"\n\nFile Not Found...";
                        goto menu;
                    }

                    fin.seekg(0);
                    gtotal=0;
                    while(!fin.eof())
                    {
                        fin.read((char*)&amt,sizeof(amt));
                        if(!fin.eof())
                        {
                            amt.report();
                            gtotal+=amt.retnetamt();
                            ff=0;
                        }
                        if(ff!=0) gtotal=0;
                    }

                    gotoxy(17,k);
                    cout<<"\n\n\n\t\t\tGrand Total="<<gtotal;
                    getch();
                    fin.close();
                }
                if(cho==2)
                {
                    goto menu;
                }
                goto ss;

            case 2: system("cls");
                            flag=0;
                            int ino;
                            cout<<"\n\n\t\tEnter Item Number :";
                            cin>>ino;
                            fin.open("itemstore.dat",ios::binary);
                            if(!fin)
                            {cout<<"\n\nFile Not Found...\nProgram Terminated!";
                            goto menu;
                            }
                            fin.seekg(0);
                            while(fin.read((char*)&amt,sizeof(amt)))
                            {
                                int x=amt.Item::retno();
                                if(x==ino)
                                {
                                    amt.pay();
                                    flag=1;
                                    break;
                                }
                            }

                            if(flag==0)
                            {
                                cout<<"\n\t\tItem does not exist....Please Retry!";
                            }
                            getch();
                            fin.close();
                            goto menu;

                    case 3: system("cls");
                            gotoxy(38,13);
                            cout<<"ARE YOU SURE, YOU WANT TO Logout (Y/N)?";
                            char yn;
                            cin>>yn;

                            if((yn=='Y')||(yn=='y'))
                            {
                                system("cls");
                                exit(0);
                            }
                            else if((yn=='N')||(yn=='n'))
                            {
                                goto menu;
                            }
                            else
                            {
                                goto menu;
                            }

                   default:gotoxy(44,18); cout<<"Wrong Choice....Please Retry!";
                            getch();
                            goto menu;
       }

                // call statement to user login menu
            }

            else
            {
                gotoxy(39,20);
                cout << "Username / Password Incorrect... Try Again..." ; Sleep(2000); goto C;
            }

    }



};



class Login : public Manager , public User
{
public:
    void menuscreen()
    {
        char opt;
        A:
        system("CLS");
        gotoxy(55,10);
        cout << "Login Menu..." << endl;
        gotoxy(48,11);
        cout<<"-------------------------"<< endl;
        gotoxy(56,13);
        cout << "1.Manager";
         gotoxy(56,14);
        cout << "2.User" ;
         gotoxy(53,16);
        cout << "Enter Option : " ;
        cin >> opt ;

        switch(opt)
        {
            case '1' : manLog(); break;
            case '2' : userLog(); break;
            default  : cout << "option Invalid... Try again..." << endl; Sleep(2000); goto A;
        }

    }
};
int main()
{
    //system("COLOR 8F");
    gotoxy(0,20);
    cout << " Loading..." << endl;
    for(int x=0; x < 120; x++)
    {
        cout << "|";
        Sleep(25);
    }

    Login st;
    st.menuscreen();
    return 0;
}
