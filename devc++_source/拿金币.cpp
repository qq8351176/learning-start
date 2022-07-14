#include<iostream>
#include <vector>
using namespace std;
int main()
{
	int x,y,z;
	cin>>x;
	vector<vector<int> >data(x);
	for(y=0;y<data.size();y++)
		data[y].resize(x);
	vector<vector<int> >dp(x);
	for(y=0;y<data.size();y++)
		dp[y].resize(x);	
	for(y=0;y<x;y++)
		for(z=0;z<x;z++)
		{
		cin>>data[y][z];
		}
	dp[0][0]=data[0][0];
	for(y=1;y<x;y++)
	{
		dp[y][0]+=dp[y-1][0];
		dp[0][y]+=dp[0][y-1];
	}
	cout>>dp[0][0];
		
	
}
