#include <iostream>
#include<set>
#include<math.h>
//ѧ���� ��ν�int����תΪ�ַ� Ϊ (char)(a+48) 
//�� char ת��Ϊ string 
//	string data;
//	data =string(1,(char)(49));
//	cout<<data;
//	����Ĳ�Ϊ5-6λ 
using namespace std;
int main()
{	
	int y;//yΪ���뵽0-54���� 
	cin>>y;
	set<int> output;//output Ϊ�洢 ���еĻ��ĵ�set���� 
	int one,ten,hundred;//��ʮ��λ 
	set<int>::iterator i =output.begin();//������ 
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
