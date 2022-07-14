#include <iostream>
using namespace std;
int main()
{
	int x,y,z,flag=1;
	cin>>x;
	int a[x];
	for(y=0;y<x;y++)
	{
		cin>>a[y];
	}
	cin>>z;
	for(int i=0;i<x;i++)
	{
		if(a[i]==z)
			{	flag=0;
				cout<<(i+1);
				break; 
			}
	}
	if(flag)
	cout<<-1;
	return 0;

}
