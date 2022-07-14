#include <iostream>
#include <string> 
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <stdio.h> 
using namespace std;
int to_num(char c)
{
	switch(c)
	{	
		case '0':
			return 0;
		case '1':
			return 1;		
		case '2':
			return 2;		
		case '3':
			return 3;		
		case '4':
			return 4;		
		case '5':
			return 5;		
		case '6':
			return 6;		
		case '7':
			return 7;		
		case '8':
			return 8;		
		case '9':
			return 9;
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
//		case 'a':
//			return 10;
//		case 'b':
//			return 11;
//		case 'c':
//			return 12;
//		case 'd':
//			return 13;
//		case 'e':
//			return 14;
//		case 'f':
//			return 15;
	}
}
int main()
{
	//int x;
	string y;
	cin>>y;
	unsigned int num=0;
	for(int i =0;i<y.length();i++)
	{
	num +=to_num(y[i])*pow(16,(y.length()-1-i));
	}
	cout<<num;
    return 0;
} 
	//cin>>x;
	//vector<string>data;
	//vector<long double>data_change;//vector<int>data_change(x) 为错误写法 会提前置0； 
	//for(int i =0;i<x;i++)
	//{	
	//	cin>>y; 
	//	data.push_back(y); 
	//}
	//vector<string>::iterator start = data.begin();
	//vector<string>::iterator end = data.end();
	//while(start != end)
	//{
		//atoi((*start).c_str());
	    //long double num=0;
		//for(int i =0;i<=(*start).length()-1;i++)
		//{
			
		//}

		//data_change.push_back(num);

	//start++;
	//}
	//for(int i =0;i<x;i++)
	//{
	//	cout<<data_change[i]<<endl;
	//} 





