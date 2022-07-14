#include <iostream>
using namespace std;

const int N = 100;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};//方向数组技巧
int n, m, T;//n行m列T障碍总数
int ans;//记录方案总数
int sx, sy, fx, fy, l, r;//起点坐标(sx,sy)终点坐标(fx,fy)障碍点坐标(l,r)
bool visited[N][N];//记录某点是否被访问过
int map[N][N];//map[i][j] == 1表示是障碍

bool check(int x, int y)//check某点是否合法
{
    if (x < 1 || x > n || y < 1 || y > m) return false;//该点出界不合法
    if (map[x][y]) return false;//该点是障碍点不合法
    if (visited[x][y]) return false;//该点被访问过不合法
    return true;//其他情况访问合法
}

void dfs(int x, int y)//dfs维护点的坐标参数
{
    if (x == fx && y == fy)//满足边界条件，到达终点
    {
        ans++;//方案数+1
        return;
    }
    for (int i = 0; i < 4; i++)//枚举四个方向
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (check(newx, newy))//该点合法
        {
            visited[x][y] = true;//将(x,y)设置成已访问,修改现场
            dfs(newx, newy);//dfs下一个点
            visited[x][y] = false;//回溯,恢复现场
        }
    }
}

int main()
{
    cin >> n >> m >> T;
    cin >> sx >> sy >> fx >> fy;
    while(T--)
    {
        cin >> l >> r;
        map[l][r] = 1;
    }
    dfs(sx, sy);//从起点开始搜索
    cout << ans << endl;
    return 0;
}

