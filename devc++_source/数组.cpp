#include<iostream> 
using namespace std; 
int main()
{
int* A = new int[10*10]();
for(int i=0;i<10;i++)
for(int X=0;X<10;X++)
cout<<A[i*10+X]; 
}

