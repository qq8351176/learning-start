//�ô��������Ϊ �ַ�����λ��0 
#include <iostream>
#include <string> 
#include <stdlib.h>
#include<set>
//ѧ���� ��ν�int����תΪ�ַ� Ϊ (char)(a+48) 
//�� char ת��Ϊ string 
//	string data;
//	data =string(1,(char)(49));
//	cout<<data;

using namespace std;
int main()
{	
	set<string> output;//output Ϊ�洢 ���еĻ��ĵ�set���� 
	int y;//yΪ���뵽0-54���� 
	string data;//dataΪÿһ�����ĵ��ݴ� 
	cin>>y;
	int one,ten,hundred;//��ʮ��λ 
	set<string>::iterator i =output.begin();//������ 
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
