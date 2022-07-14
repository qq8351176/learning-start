#include<bits/stdc++.h>
//bits/stdc++.h 包含所有的头文件 
//next_permutation 下一个排列数 
using namespace std;
int A(int n,int m)
{	
	if(m==0)return 1;
	return A(n-1,m-1)*n;
}
int C(int n,int m)
{	  
	
return A(n,m)/A(m,m);
}
int main(){
    int n,num;
    cin>>n>>num;
    vector<int> a(n); 
    for(int i=0;i<n;i++) a[i]=i+1;
	while(true)
	{	int sum=0;
		for(int i=0;i<a.size();i++)
		{
			sum+=a[i]*C(n-1,i);
		}
		if(sum==num)
		{	
		for(int i=0;i<a.size();i++)
		{
			cout<<a[i]<<" ";		
		}
					break;
		}

		if(next_permutation(a.begin(),a.end()));
		else break;

	}

    return 0;
}


//	    do{
//        vector<int> b=a;
//        for(int i=0;i<n-1;i++){
//            for(int j=0;j<n-i+1;j++){
//                b[j]=b[j]+b[j+1];
//            }
//        }
//        if(b[0]==num){
//            for(int i=0;i<n;i++){
//                if(i!=n-1) cout<<a[i]<<" ";
//                else cout<<a[i]<<endl;
//            }
//            break;
//        }
//    }
