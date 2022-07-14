#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	int n,sum = 0;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		sum += a[i];//求总和 
	}
	int sum1 = sum / 2;
	sort(a,a + n);//从小到大排序 
	int res = 0;//相等的最大长度 
	for(int i = n - 1;i >= 0;i--){
		if(sum1 >= a[i] + res){//数组从后向前累加正好不大于1/2sum值的res值就是最大长度 
			res += a[i];
		}
	}
	cout<<res<<endl;
	return 0;
} 
