#include <iostream>
#include <list>
using namespace std;
int main(){
  int x,y;
	cin>>x;
	list<int>ls;
	for(int i=0;i<x;i++)
	{
		
		cin>>y;
		ls.push_back(y);
	}
	ls.sort();
	list<int>::iterator frist = ls.begin();
	list<int>::iterator end = ls.end();
	while(frist != end)
	{
	    cout<<*frist<<" ";
		frist++;
	}
	return 0;
}

