#include <bits/stdc++.h>
#include<set>
using namespace std;
struct {
	double x;
	double y;
}point[400];
struct fraction{
int up;
int down;
int c;
}; 
bool operator<(fraction num1,fraction num2)
{
	if(num1.down==num2.down)
	{
		if(num1.up<num2.up)
		{
			if(num1.c<num2.c)
			return true;
		}
	}
	else{
		num1.up=num1.up*num2.down;
		num2.up=num2.up*num1.down;
		num1.down=num1.down*num2.down;
		num2.down=num1.down;
		if(num1.up<num2.up)
		{
			if(num1.c<num2.c)
			return true;
		}
	}
	return false;
}
int  main()
{	
	set<fraction> k; 
	int num =0;
	int m=2;int n=3;
	for(int x=0;x<m;x++)
		for(int y=0;y<n;y++)
		{
			point[num].x=x;
			point[num].y=y;
			num++;
		}
		num=0;
	for(int i=0;i<m*n;i++)
		for(int z =i+1;z<m*n;z++)
		{
			if(point[i].x!=point[z].x&&point[i].y!=point[z].y)
			{
			struct fraction fra;
			fra.up=(point[i].y-point[z].y);
			fra.down=(point[i].x-point[z].x);
			fra.c=point[i].y * (point[i].x-point[z].x)- point[i].x *(point[i].y-point[z].y);;	
			cout<<fra.up<<'/';
			cout<<fra.down<<"  "<<fra.c<<endl;
			k.insert(fra);
			}
		}
		cout<<k.size()+m+n;
}

