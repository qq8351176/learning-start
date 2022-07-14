#include <iostream>
using namespace std;

int a[100], b[100], c[100], d[100];//a[]储存解b列c左斜d右斜
int n;//棋盘大小
int ans;

bool check(int i, int j)//检查(i,j)是否合法
{
    if (!b[j] && !c[j - i + n] && !d[j + i]) return true;//b[j],c[i-j+n],d[i+j]为0说明该点可以放置棋子。
    return false;
}

void dfs(int i)//dfs第i行棋子
{   //边界条件
    if (i > n)//dfs完所有的棋子
    {
     	ans++;
        if (ans <= 3)//只要前三个解
        {
            for (int i = 1; i <= n; i++)//输出解
            {
                cout << a[i] << ' ';
                
            }
            cout << endl;  
        }
        return;     
    }
    
        for (int j = 1; j <= n; j++)//枚举一行的所有位置
        {	//(i,j)点满足放棋子的条件，我们就把棋子放在(i,j)点
            if (check(i, j))
            {
                a[i] = j;//把满足解的列号存在a[i]中
                b[j] = 1;//修改现场
                c[ j - i + n] = 1;
                d[j + i] = 1;
                dfs(i + 1);//处理下一行的棋子
                b[j] = 0;//回溯，恢复现场
                c[j - i + n] = 0;
                d[j + i] = 0;
            }
        }
}
int main()
{
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}
