#include <iostream>
using namespace std;
int map[11][11];
int a[11]; // a[]储存解
int n;      //棋盘大小
int ans;

bool check(int i, int j) //检查(i,j)是否合法
{
    if (!map[i][j])
        return true; // b[j],c[i-j+n],d[i+j]为0说明该点可以放置棋子。
    return false;
}
void set(int i, int j, int x)
{
    for (int z = 1; z <= n; z++)
    {
        map[z][j] += x;
        map[i][z] += x;
    }
    for (int z = 1; z <= n; z++)
    {
        if (i + z <= n && j + z <= n)
        {
            map[i + z][j + z] += x;
        }
        if (i + z <= n && j - z >= 1)
        {
            map[i + z][j - z] += x;
        }
        if (i - z >= 1 && j + z <= n)
        {
            map[i - z][j + z] += x;
        }
        if (i - z >= 1 && j - z >= 1)
        {
            map[i - z][j - z] += x;
        }
    }
}
void dfs(int i) // dfs第i行棋子
{               //边界条件
    if (i > n)  // dfs完所有的棋子
    {;
        ans++;
        if (ans <= 3) //只要前三个解
        {
            for (int i = 1; i <= n; i++) //输出解
            {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
        return;
    }

    for (int j = 1; j <= n; j++) //枚举一行的所有位置
    {                            //(i,j)点满足放棋子的条件，我们就把棋子放在(i,j)点
        if (check(i, j))
        {
            a[i] = j; //把满足解的列号存在a[i]中
            set(i, j, 1);
            dfs(i + 1); //处理下一行的棋子
            set(i, j, -1);
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
