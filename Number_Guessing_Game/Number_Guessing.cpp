#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
using namespace std;
void printHeading()
{
    //Set Text Color to Yellow
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t   =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<"\t\t\t\t   |      WELCOME TO NUMBER GUESSING GAME      |"<<endl;
    cout<<"\t\t\t\t   =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*="<<endl;
    cout<<endl;
}
int main()
{
    int org_number,guessed_number;
    char ch;
    srand(time(0));
    org_number=1+rand()%100;
    while(1)
    {
        //This loop will be execute until valid input is given
        while(1) 
        {
            system("cls");
            printHeading();
            //Set Text Color to white
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            cout<<"\t\t\t\t       Guess a number between 1 & 100 : ";
            cin>>guessed_number;  
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }          
            else
                break;            
        }
        /*Checking for the goal*/
        if(org_number==guessed_number)
        {
            system("cls");
            printHeading();
            //Set Text Color to Green
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            cout<<"\t\t\t\t     Congratulations !!! Your guess is correct.  "<<endl;
            //Set Text Color to White
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            break;
        }
        else
        {
            //Set Text Color to Light Purple
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
            if(guessed_number>org_number)
                cout<<"\t\t\t\t       Too high... "<<endl;
            else
                cout<<"\t\t\t\t       Too low... "<<endl;
            //Set Text Color to Aqua
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
            cout<<"\t\t\t\t       Do you want to try it again ? (Y/N) ";
            do
            {
                ch=getch();
            }while(ch!='N' && ch!='n' && ch!='Y' && ch!='y');
            if(ch=='N' || ch=='n')
            {
                system("cls");
                printHeading();
                //Set Text Color to Red
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                cout<<"\t\t\t\t     Opps!!! Better luck next time.  "<<endl;
                //Set Text Color to White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                break;
            }
            
        }
    }    
    cout<<"\t\t\t\t     Do you want to play it again ? (Y/N)  ";
    do
    {
        ch=getch();
    }while(ch!='N' && ch!='n' && ch!='Y' && ch!='y');
    if(ch=='Y' || ch=='y')
        main();
    else
    {
        cout<<endl<<"\t\t\t\t     Exiting...  ";
        getch();
    }
    return 0;
}
