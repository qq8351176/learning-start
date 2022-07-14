#include<iostream>
#include<algorithm>
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
    int i=1;
    long long time=0;
    long long zhou=a*5+b*2;
    while (true)
    {
        if((n/zhou)!=0)
        {
            time+=7*(n/zhou);
            n=n%zhou;
        }
        else{
            {
                if(n<0)
                    break;
                if(n==0)
                {
                    break;
                }
                time++;
                n=n-data[i];
                i++;
                if(i==7)
                i=1;

            }
        }

        

    }   

    cout<<time;
    return 0; 
} 
