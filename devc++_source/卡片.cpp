#include <bits/stdc++.h>
using namespace std;
int check(int i) {
	int sum=0;
	string s =to_string(i);
	for(int x = s.size()-1;x>=0;x--)
	if(s[x]=='1')
	sum+=1;
	return sum;
}
int main() {
	int i=1;
	int num=3; 
	while(true) {
	num-=check(i);

	if(num<0)
	{i--;break;
	}
		i++;
	}
	cout<<i;
}
