/* creating a fibonacci series using cpp */

#include<iostream>
using namespace std;
int fibo(int n)
{
    if(n<2)
    {
        return 1;
    } return fibo(n-1)+fibo(n-2);
}
int main()
{
    int a ;
    cout<<"enter the number"<<endl;
    cin>>a;

   cout<<"the fibonacci number at position "<<a<< " is "<<fibo(a)<<endl; 
return 0;
}
