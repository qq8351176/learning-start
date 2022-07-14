#include <iostream> 
#include <string>
using namespace std;
int main()
{
	char s[10]={'0','1','2','3','4','5','6','7','8','9'};

	for(int i =1;i<=9;i++)
		for(int x=0;x<=9;x++)
		{
			cout<<(s[i]);
			cout<<(s[x]);
			cout<<(s[x]);
			cout<<(s[i]);
			cout<<endl;
		} 
}
