#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int n,ans=0;
    cin>>n;
    cout<<"5分 2分 1分  序号"<<endl;
    for(int x=0;x<=n/5;x++)
    for(int y=0;y<=n/2;y++)
    for(int z=0;z<=n/1;z++)
    if(x*5+y*2+z*1==n)
    cout<<x<<"  "<<y<<"   "<<z<<"     "<<++ans<<endl;
    return 0;
  }
