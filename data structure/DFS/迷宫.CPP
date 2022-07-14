#include <iostream>
using namespace std;
const int N = 100;        //设定一个常量用来设定数组的大小
int dx[] = {0, 0, -1, 1}; //设定一个方向数组
int dy[] = {1, -1, 0, 0};
int n, m, T;
int ans; //方案总数
int sx, sy, fx, fy, l, r;
bool visted[N][N];
int map[N][N];
bool check(int x, int y)
{
    if (x < 1 || x > n || y > m || y < 1)
        return false;
    if (visted[x][y] == 1)
        return false;
    if (map[x][y] == 1)
        return false;
    return true;
}
void dfs(int x, int y)
{
    if (x == fx && y == fy)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) //重点枚举方向
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (check(newx, newy))
        {

            visted[x][y] = true;
            for (int a = 1; a <= n; a++)
            {
                for (int b = 1; b <= m; b++)
                {
                    if (visted[a][b])
                    {
                        cout << '*';
                    }
                    else
                        if (map[a][b]==1)
                        {
                            cout<<'X';
                        }
                        else    
                        cout << 0;
                }
                cout << endl;
            }

            dfs(newx, newy);
            visted[x][y] = false;
        }
    }
}
int main()
{
    cin >> n >> m >> T;
    cin >> sx >> sy >> fx >> fy;
    while (T--)
    {
        cin >> l >> r;
        map[l][r] = 1;
    }
    dfs(sx, sy); //从起点开始搜索
    cout << ans << endl;
    return 0;
}
