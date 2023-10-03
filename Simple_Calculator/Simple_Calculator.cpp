#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    float a,b,res;
    char op;
    cout<<"SIMPLE CALCULATOR"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Enter first number : ";
    cin>>a;
    cout<<"Enter second number : ";
    cin>>b;
    cout<<"Enter operator (+,-,*,/) : ";
    cin>>op;
    switch (op)
    {
        case '+':
            res=a+b;
            cout<<res;
            break;
        case '-':
            res=a-b;
            cout<<res;
            break;
        case '*':
            res=a*b;
            cout<<res;
            break;
        case '/':
            res=a/b;
            cout<<res;
            break;
        default:
            cout<<"Invalid operator";
    }
    getch();
    return 0;
}