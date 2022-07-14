#include <stdio.h>
#include <iostream>
using namespace std;
//5位到6位固定输出 
int main ()
{
	int a,b,c,d,e,f;
	int flag=0;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		cout<<n<<endl;
		int i;
	for(i=10000;i<999999;i++)
	{
		if(i/100000==0)
		{
			a=i%10;
		    b=((i-a)/10)%10;
			c=((((i-a)/10)-b)/10)%10;
			d=((((((i-a)/10)-b)/10)-c)/10)%10;
			e=((((((((i-a)/10)-b)/10)-c)/10)-d)/10)%10;
			int sum= a*10000+b*1000+c*100+d*10+e*1;
			if(sum==i && a+b+c+d+e==n)
			{
		  		printf("%d\n",sum);
		  		
    		}
		}
		else
		{
			a=i%10;
			b=((i-a)/10)%10;
			c=((((i-a)/10)-b)/10)%10;
			d=((((((i-a)/10)-b)/10)-c)/10)%10;
			e=((((((((i-a)/10)-b)/10)-c)/10)-d)/10)%10;
			f=((((((((((i-a)/10)-b)/10)-c)/10)-d)/10)-e)/10)%10;
			int sum= a*100000+b*10000+c*1000+d*100+e*10+f;
			if(sum==i && a+b+c+d+e+f==n)
			{
		 		 printf("%d\n",sum);
    		}
		}
	}   
		
	}
	return 0;
}

