#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
using namespace std;

double result(double n,double m)
{
    vector<vector<double> > res(m+1);
    double i=0,j=0;
    double p =1.0/n;
    for(i=0;i<res.size();i++)
       res[i].resize(n+1);
    for(i=1;i<=m;i++)
    {
    for(j=1;j<=n;j++)
    {
    if(i<j)
    res[i][j]=0;
    if(j==1)
    res[i][j]=pow(p,i-1);
    else
    res[i][j]=res[i-1][j]*(j*p)+res[i-1][j-1] * ((n-j+1)*p);
    }
    }
    
    return res[m][n];
}
int main()
{
    double n,m;
    cin>>n>>m;
    double res;
    res=result(n,m);
    cout<<fixed<<setprecision(4)<<res;
}
