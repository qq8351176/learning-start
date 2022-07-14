#include <iostream>
#include <vector>
using namespace std;
int main()
{		
    int n,i,x;
	cin>>n;
	vector< vector<int> > data(n);
	for (i = 0; i < data.size(); i++)
    		data[i].resize(i+2,0);
	data[1][1]=1;
	for(i =0;i<n;i++)
	{
		data[i][0]=1;
	}

	for(i=2;i<n;i++)
		for(x=1;x<=i;x++)
		{
			data[i][x]=data[i-1][x]+data[i-1][x-1];
		}
	for(i=0;i<n;i++)
		{
		for(x=0;x<=i;x++)
			{
			cout<<data[i][x]<<" ";
			}
		cout<<endl;
		}
	return 0; 
}
 
