#include<iostream>
using namespace std;
int main()
{
	int f1=1,f2=1,f3=2;
	int x;cin>>x;
	while(--x)
	{
		f3=f1+f2;
		f1=f2;f2=f3;f3=f2+f1;
	} 
	cout<<(f1%10007);
} 
