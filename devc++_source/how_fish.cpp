#include <iostream>
using namespace std;
int main()
{
	int min,max,n,i,j,ans;
	int a[51];
	cin>>min>>max>>n;
	for(i=0;i<n;i++)
	cin>>a[i]; 
	ans=0;
	int flag;
	for(i=min;i<=max;i++)
	{
		flag=1;
		for(j=0;j<n;j++)
		{
			if((a[j]>=i*2 && a[j]<=i*10)||(i>=a[j]*2&&i<=a[j]*10))
			{
				flag=0;
				break;
			}
		}
		if(flag) ans++;
	}
	cout<<ans<<endl;
	return 0;
} 