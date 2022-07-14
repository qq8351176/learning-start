//该代码输出的为 字符串高位补0 
#include <iostream>
#include <string> 
#include <stdlib.h>
#include<set>
//学到了 如何将int型数转为字符 为 (char)(a+48) 
//将 char 转换为 string 
//	string data;
//	data =string(1,(char)(49));
//	cout<<data;

using namespace std;
int main()
{	
	set<string> output;//output 为存储 所有的回文的set容器 
	int y;//y为输入到0-54的数 
	string data;//data为每一个回文的暂存 
	cin>>y;
	int one,ten,hundred;//个十百位 
	set<string>::iterator i =output.begin();//迭代器 
	if(y%2==0)
	{
		for(hundred=0;hundred<10;hundred++)
			for(ten=0;ten<10;ten++)
				for(one=0;one<10;one++)
				{	
					if((hundred+ten+one)==y/2)
					{	
						data.append(string(1,(char)(hundred+48)));
						data.append(string(1,(char)(ten+48)));
						data.append(string(1,(char)(one+48)));
						data.append(string(1,(char)(one+48)));
						data.append(string(1,(char)(ten+48)));
						data.append(string(1,(char)(hundred+48)));
						output.insert(data);
						data="";	
					}
				}
				
	}
	else
	{
		for(int i =1;i<=9&&(!(i>y));i+=2) 
		{
			for(hundred=0;hundred<10;hundred++)
				for(ten=0;ten<10;ten++)
				{	if((hundred+ten)==(y-i)/2)
					{	
						data.append(string(1,(char)(hundred+48)));
						data.append(string(1,(char)(ten+48)));
						data.append(string(1,(char)(i+48)));
						data.append(string(1,(char)(ten+48)));
						data.append(string(1,(char)(hundred+48)));
						output.insert(data);
						data="";
					}	
				}
		}
	} 
	for(set<string>::iterator i = output.begin();i!=output.end();i++)
	cout<<*i<<endl;
	return 0;
} 
