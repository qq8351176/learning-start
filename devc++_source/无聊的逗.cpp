#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	int n,sum = 0;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		sum += a[i];//���ܺ� 
	}
	int sum1 = sum / 2;
	sort(a,a + n);//��С�������� 
	int res = 0;//��ȵ���󳤶� 
	for(int i = n - 1;i >= 0;i--){
		if(sum1 >= a[i] + res){//����Ӻ���ǰ�ۼ����ò�����1/2sumֵ��resֵ������󳤶� 
			res += a[i];
		}
	}
	cout<<res<<endl;
	return 0;
} 
