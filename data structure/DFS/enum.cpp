#include <iostream>
using namespace std;

const int N = 11;
//map[N]储存当前的排列，hashtable[N]判断某个数是否在排列里
int map[N];
bool hashtable[N];
int n;

void dfs(int index)//当前填第index位置
{
    if (index == n + 1)//已经处理完1~n个位置
    {
        for (int i = 1; i <= n; i++)//输出当前排列
        {
            cout << map[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)//枚举1~n
    {
        if (hashtable[i] == false)//当i这个数没有填在map中
        {
            map[index] = i;//第index位置填入i这个数
            hashtable[i] = true;//记i在当前排列
            dfs(index + 1);//处理第index+1位置
            //处理完map[index]=i的子问题，恢复现场
            hashtable[i] = false;
            map[index] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);//从1这个数开始搜索
    return 0;
}
