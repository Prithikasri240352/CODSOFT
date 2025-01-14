//R.Prithikasri CODSOFT Task2:Simple Calculator
#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
    char op;
     cout<<"Enter input1: "<<endl;
    cin>>n1;
    cout<<"Enter input2 : "<<endl;
    cin>>n2;
    cout<<"Enter operations (+,-.*,/) : "<<endl;
    cin>>op;
    
    switch(op)
    {
        case '+' :
        cout<<"Addition of your input is : "<< n1 + n2;
        break;
        case '-' :
        cout<<"Subtraction of your input is : "<< n1 - n2;
        break;
        case '*' :
        cout<<"Multiplication of your input is : "<< n1 * n2;
        break;
        case '/' :
        cout<<"Division of your input is : "<<n1 / n2;
        break;
        default:
        cout<<"Enter correct operation."<<endl;
    }
    return 0;
}