#include <iostream>
using namespace std; 
int main()
{
	unsigned long long n=0,s=0;
	unsigned long long sum1=0,sum2=0,max=0,k=0;
	cin>>n>>s;   
	unsigned long long a[n+1];
	int i =0;
	a[0]=0;
	for(i =1;i<=n;i++)
	{
	cin>>a[i];
	}
	for(i=1;i<=n-1;i++)
	{	
		for(k=1;k<=n/2;k++)
		{
			if(i+1-k==0||i-1+k==n)
			{
			sum1=0;sum2=0; break;
			}	
			sum1+=a[i+1-k];
			sum2+=a[i+k];
			if(sum1>s||sum2>s)
			{	
				sum1=0;sum2=0; 
				break;
			} 
		}
		if(k>max)
		max=k-1;
	}
	cout<<max*2;
}
