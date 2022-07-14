//20软工二班康文迪
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, less<int>> a;
    priority_queue<int, vector<int>, greater<int>> b;
    int n;
    int x;
    cout << "输入数组的个数:";
    cin >> n;
    cout << "请输入" << n << "个数字";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b.push(x);
        if (b.size() - a.size() == 2)
        {
            x = b.top();
            b.pop();
            a.push(x);
        }
    }
    if(b.size()-a.size()==1)
    cout<<"中位数"<<b.top();
    else cout<<"中位数"<<a.top();
}