#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int left=1,right=n;
    vector<int>data;
    for(int i=1;i<=n;i++)
    {
    	if(abs(i-left)<abs(i-right)){
    		data.push_back(abs(i-right)*2);
		}
    	else if(abs(i-left)>abs(i-right))
    	{
    		data.push_back(abs(i-left)*2);
		}
    	else
    	{
    		data.push_back(abs(i-left)*2);
		}
	}
	for(int i=0;i<n;i++)
	{cout<<data[i]<<endl;
	}
	return 0;
}
