#include <iostream>
using namespace std;
void bincout(int x,int number)
{
	number--;
	if(number!=0)
	bincout(x/2,number);
	cout<<x%2;
	
}
int main()
{
	unsigned int x;
	for(int i=0;i<=31;i++)
	{
		bincout(i,5);
		cout<<endl;
	}
}
