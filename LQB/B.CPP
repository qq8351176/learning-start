#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
  int a[]={0,0,0,0};
  for (int i = 0; i <= 1; i++)
    for (int x = 0; x < 9; x++)
      for (int y = 0; y < 9; y++)
        for (int z = 0; z < 9; z++)
        {
          a[0]=i;
          a[1]=x;
          a[2]=y;
          a[3]=z;
          if(((a[1]-a[0])==1)&&((a[2]-a[1])==1))
            cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;
          if(((a[3]-a[2])==1)&&((a[2]-a[1])==1))
            cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;
        }
} 
