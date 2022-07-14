//#include<bits/stdc++.h>
//using namespace std; 
#include<iostream>
#include<cmath>
#include<set>
using namespace std;
struct node{//点
    int x,y;
}p[1000];
struct line{//直线
    int a,b,c;//直线一般方程的系数
    bool operator<(const line &p) const {
        if (a == p.a) return b == p.b ? c < p.c : b < p.b;
        return a < p.a;
    }
    bool operator==(const line &p) const {
        return a == p.a && b == p.b && c == p.c;
    }
};
int cnt;
set<line> se;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int gcdd(int a,int b,int c){
    return gcd(gcd(a,b),gcd(b,c));
}
int main()
{
    int n=3,m=3;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            p[++cnt]={i,j};
    for(int i=1;i<=cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            int a=p[i].y-p[j].y;//系数
            int b=p[j].x-p[i].x;
            int c=p[i].y * (p[i].x-p[j].x)- p[i].x *(p[i].y-p[j].y);
            int t=gcdd(fabs(a),fabs(b),fabs(c));
            se.insert({a/t,b/t,c/t});
        }

    }
    cout<<se.size();
    return 0;
}

