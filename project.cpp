#include <iostream>
#include <conio.h>
#include <fstream>
#include<string>
#include <windows.h>
using namespace std;

class A
{
public:

    char name[50];
    char acc_type[50];
    int amount;

    void open_acc()
    {
        cout<<"Enter name:: ";              cin.get(name,50);       cin.ignore();
        cout<<"Enter Account Type(c/s):: ";      cin.get(acc_type,50);
        cout<<"Enter Initial Amount:: ";    cin>>amount;
    }

    void show()
    {
        cout<<"Name         :: "<<name<<endl;
        cout<<"Account Type :: "<<acc_type<<endl;
        cout<<"Amount       :: "<<amount<<endl;
    }
};

int main()
{

    system("COLOR 0A");
    int choice,found=0,balance=0;
    char s_name[50];

    while(1)
    {
        system("cls");
        Sleep(200);
        cout<<"--------HOME PAGE--------"<<endl;
        cout<<"1. Admin"<<endl;
        Sleep(200);
        cout<<"2. User"<<endl;
        Sleep(200);
        cout<<"3. Exit"<<endl;
        Sleep(200);
        cout<<"4. About Programmar"<<endl;
        Sleep(200);
        cout<<"Enter your choice:: ";   cin>>choice;

        switch(choice)
        {
        case 1:// for admin
            {
                cin.ignore();
                system("cls");
                cout<<"loading";
                Sleep(700);
                system("cls");
                cout<<"loading.";
                Sleep(700);
                system("cls");
                    cout<<"loading..";
                    Sleep(700);
                    system("cls");
                    cout<<"loading...";
                    system("cls");
                string pass,usr;
                int comp1,comp2;
                string adusr="123",adpass="123";
                system("cls");
                cout<<"ENTER USERNAME:  ";cin>>usr;
                cout<<"ENTER PASSWORD: ";cin>>pass;
                comp1=adusr.compare(usr);
                comp2=adpass.compare(pass);
                if(comp1==0 && comp2==0)
                {
                    while(1)
                    {
                        system("cls");
                 cout<<"loading";
                    Sleep(700);
                    system("cls");
                    cout<<"loading.";
                    Sleep(700);
                    system("cls");
                    cout<<"loading..";
                    Sleep(700);
                    system("cls");
                    cout<<"loading...";
                    system("cls");
                        system("cls");
                        Sleep(200);
                        cout<<"-------ADMIN---------"<<endl;
                        Sleep(200);
                        cout<<"\n\n\t01. NEW ACCOUNT";
                        Sleep(200);
                        cout<<"\n\n\t02. ALL ACCOUNT LIST";
                        Sleep(200);
                        cout<<"\n\n\t03. CLOSE AN ACCOUNT";
                        Sleep(200);
                        cout<<"\n\n\t04. EXIT";
                        Sleep(200);
                        cout<<"\n\n\tSelect Your Option (1-4) ";
                        cin>>choice;

                        switch(choice)
                        {
                        case 1://new account
                            {
                                cin.ignore();
                                A a;
                                a.open_acc();
                                fstream file("main",ios::app);
                                file.write((char*)&a,sizeof(a));
                                file.close();
                                cout<<endl<<endl<<"Account has been created"<<endl;
                                cout<<"press any key to continue..."<<endl;
                                getch();
                                continue;
                            }
                        case 2:// display all account
                            {
                                A a;
                                found=1;
                                fstream file("main",ios::in);
                                while(file.read((char*)&a,sizeof(a)))
                                {
                                    cout<<"Account number:: "<<found<<endl;
                                    a.show();
                                    found++;
                                }
                                file.close();
                                cout<<"press any key to continue..."<<endl;
                                getch();
                                continue;
                            }
                        case 3://delete account
                            {
                                A a;
                                found=0;
                                cin.ignore();
                                cout<<"Enter name to delete:: ";        cin.get(s_name,50);
                                fstream file("main",ios::in);
                                fstream file1("main1",ios::out);
                                while(file.read((char*)&a,sizeof(a)))
                                {
                                    if(strcmp(a.name,s_name)!=0)
                                    {
                                        file1.write((char*)&a,sizeof(a));
                                    }
                                    else
                                        found=1;
                                }
                                file.close();
                                file1.close();

                                file.open("main",ios::out);//15745
                                file1.open("main1",ios::in);

                                while(file1.read((char*)&a,sizeof(a)))
                                    file.write((char*)&a,sizeof(a));

                                file.close();
                                file1.close();
                                if(found==1)
                                    cout<<"Account has been closed"<<endl<<endl;
                                else
                                    cout<<"Account not found"<<endl<<endl;
                                cout<<"press any key to continue "<<endl;

                                getch();
                                continue;
                            }
                        case 4://exit
                            {
                                break;
                            }

                        default:
                            {
                                continue;
                            }
                        }
                        break;
                    }
                    continue;
                }
                else
                {
                    cout<<"password doesn't match"<<endl;
                    Sleep(700);
                    continue;
                }
            }//CASE 1 ADMIN



        case 2://for normal user
            {
                while(1)
                {
                    system("cls");
                 cout<<"loading";
                    Sleep(700);
                    system("cls");
                    cout<<"loading.";
                    Sleep(700);
                    system("cls");
                    cout<<"loading..";
                    Sleep(700);
                    system("cls");
                    cout<<"loading...";
                    system("cls");
                    cin.ignore();
                    Sleep(200);
                    cout<<"----------USER MENU--------------"<<endl;
                    Sleep(200);
                    cout<<"1. Deposit"<<endl;
                    Sleep(200);
                    cout<<"2. Withdraw"<<endl;
                    Sleep(200);
                    cout<<"3. Account Details"<<endl;
                    Sleep(200);
                    cout<<"4. Back to main menu"<<endl;
                    Sleep(200);
                    cout<<"Enter your choice:: ";     cin>>choice;

                    switch(choice)
                    {
                    case 1://for deposit
                        {
                            A a;
                            cin.ignore();
                            cout<<"Enter name:: ";      cin.get(s_name,50);
                            cout<<"Enter amount to deposit:: ";     cin>>choice;
                            fstream file("main",ios::in);
                            fstream file1("main1",ios::out);
                            while(file.read((char*)&a,sizeof(a)))
                            {
                                if(strcmp(a.name,s_name)==0)
                                {
                                    a.amount=choice+ a.amount;
                                    file1.write((char*)&a,sizeof(a));
                                }
                                else
                                {
                                    file1.write((char*)&a,sizeof(a));
                                }
                            }
                            file.close();
                            file1.close();

                            file.open("main",ios::out);
                            file1.open("main1",ios::in);
                            while(file1.read((char*)&a,sizeof(a)))
                                file.write((char*)&a,sizeof(a));

                            file.close();
                            file1.close();

                            cout<<"Amount has been deposited"<<endl<<endl;
                            cout<<"press any key to continue..."<<endl;
                            getch();
                            continue;
                        }
                        case 2://to widthdraw
                        {
                            A a;
                            cin.ignore();
                            cout<<"Enter name:: ";      cin.get(s_name,50);
                            cout<<"Enter amount to Withdraw:: ";     cin>>choice;
                            fstream file("main",ios::in);
                            fstream file1("main1",ios::out);
                            while(file.read((char*)&a,sizeof(a)))
                            {
                                if(strcmp(a.name,s_name)==0)
                                {
                                    balance=a.amount;
                                    a.amount=a.amount - choice;
                                    if(a.amount<0)
                                    {
                                        a.amount=0;
                                        cout<<"Maximum balance withdraw is:: "<<balance<<endl;
                                    }
                                    file1.write((char*)&a,sizeof(a));
                                }
                                else
                                {
                                    file1.write((char*)&a,sizeof(a));
                                }
                            }
                            file.close();
                            file1.close();

                            file.open("main",ios::out);
                            file1.open("main1",ios::in);
                            while(file1.read((char*)&a,sizeof(a)))
                                file.write((char*)&a,sizeof(a));

                            file.close();
                            file1.close();

                            cout<<"Amount has been withdraw"<<endl<<endl;
                            cout<<"press any key to continue..."<<endl;
                            getch();
                            continue;
                        }
                    case 3://details of account
                        {
                            A a;
                            found=1;
                            fstream file("main",ios::in);
                            cin.ignore();
                            cout<<"Enter your name:: ";     cin.get(s_name,50);
                            while(file.read((char*)&a,sizeof(a)))
                            {
                                if(strcmp(a.name,s_name)==0)
                                {
                                    cout<<"Account Number:: "<<found<<endl;
                                    a.show();
                                }
                                found++;
                            }
                            file.close();
                            cout<<endl<<"press any key to continue..."<<endl;
                            getch();
                            continue;
                        }
                    case 4: //exit
                        {
                            break;
                        }
                    }
                    break;
                }
                continue;
            }//USER CASE

        case 3:
            {
                break;
            }
        case 4:// about programmer
        	{
        		case 5:
                        	{
                        		cout<<"Name       :: Sandeep Kannaujiya"<<endl;
                        		Sleep(200);
                        		cout<<"University :: Lovely Proffesional University"<<endl;
                        		Sleep(200);
                        		cout<<"Stream     :: Computer Science Engineering"<<endl;
                        		Sleep(200);
                        		cout<<"Mobile     :: 9653000874"<<endl;
                        		Sleep(200);
                        		cout<<"Email Id   :: sandeepkannaujiya.123@gmail.com"<<endl<<endl;
                        		cout<<"Press Enter for main menu"<<endl;
                        		getch();
                        		continue;
							}
			}
        }
        break;
    }
    return 0;
}
