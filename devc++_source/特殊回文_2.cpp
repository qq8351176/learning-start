#include <iostream>
#include<set>
#include<math.h>
//学到了 如何将int型数转为字符 为 (char)(a+48) 
//将 char 转换为 string 
//	string data;
//	data =string(1,(char)(49));
//	cout<<data;
//	输入的不为5-6位 
using namespace std;
int main()
{	
	int y;//y为输入到0-54的数 
	cin>>y;
	set<int> output;//output 为存储 所有的回文的set容器 
	int one,ten,hundred;//个十百位 
	set<int>::iterator i =output.begin();//迭代器 
	if(y%2==0)
	{
		for(hundred=0;hundred<10;hundred++)
			for(ten=0;ten<10;ten++)
				for(one=0;one<10;one++)
				{	
				if(one+ten+hundred==y/2&&hundred!=0)
					{
					output.insert(hundred*pow(10,5)+ten*pow(10,4)+one*pow(10,3)+one*pow(10,2)+ten*pow(10,1)+hundred*pow(10,0));	
					if(one<5)
					output.insert(hundred*pow(10,4)+ten*pow(10,3)+one*2*pow(10,2)+ten*pow(10,1)+hundred*pow(10,0));
					}
				}
				
	}
	else
	{
		for(int i =1;i<=9&&(!(i>y));i+=2) 
		{
			for(hundred=0;hundred<10;hundred++)
				for(ten=0;ten<10;ten++)
				{	if((hundred+ten)==(y-i)/2&&hundred!=0)
					{	
						output.insert(hundred*pow(10,4)+ten*pow(10,3)+i*pow(10,2)+ten*pow(10,1)+hundred*pow(10,0));

					}	
				}
		}
	} 
	for(set<int>::iterator i = output.begin();i!=output.end();i++)
	cout<<*i<<endl;
	return 0;
} 
