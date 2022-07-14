#include <iostream>
using namespace std;
int main()
{
	int max=0,min=0,sum=0,x,y;
	cin>>x;
	cin>>y;
	max=y;
	min=y;
	sum+=y;
	for(int i=1;i<x;i++)
	{
		cin>>y;
		if(y>max)
		max=y;
		if(y<min)
		min=y;
		sum+=y;
	}
	cout<<max<<endl<<min<<endl<<sum<<endl;
} 
