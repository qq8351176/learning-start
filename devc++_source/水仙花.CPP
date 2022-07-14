#include <stdio.h>
#include <iostream>
using namespace std; 
int main()
{	
	int x,y,z;
	for(int i=100;i<=999;i++)
	{
		x=i/100;
		y=(i/10)%10;
		z=i%10;
		if(x*x*x+y*y*y+z*z*z==i)
		cout<<i<<endl;
	}
}
