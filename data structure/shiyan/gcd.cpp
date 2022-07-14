#include<iostream>
using namespace std;
int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}

int main()
{
    cout<<gcd(20,25);
    int x,y;
    x=20;y=25;
    while (x%y)
    {
        int temp;
        temp=x;
        x=y;
        y=temp%y;
    }
    cout<<y;
    
}
//软件工程二班康文迪