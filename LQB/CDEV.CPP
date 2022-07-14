#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{   
    long long a,b,n;
    cin>>a>>b>>n;
    long long data[8];
    for(int i=1;i<=7;i++)
    {
        if(i<=5)
        data[i]=a;
        else 
        data[i]=b;
    }
    for(int i=1;i<=7;i++)
    {
        cout<<data[i];
    }
} 

