#include <iostream>
using namespace std;
int n, m, k;
int ans = 0;
int a[500 + 1][500 + 1];
int dp[500 + 1][500 + 1];
int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{	int sum=0;
			for(int x=i+1;x<=n;x++)
			{
				sum+=a[x][j];
				if(sum<k)ans++;
			}
			sum=0;
			for(int y=j+1;y<=m;y++)
			{
				sum+=a[i][y];
				if(sum<k)ans++;
			}
			sum=0;
			for()
		}
			cout<<ans;
	return 0;
}
// int dx[]={-1,1,0,0};//�� �� �� ��
// int dy[]={0,0,-1,1};
//void ans()
//{
//int i=0;
//
//}
//void bfs()
//{
//    for (int i = 0; i <= n; i++)
//        for (int j = 0; j <= m; j++)
//        {
//
//        }
//
//}
//int main()
//{
//    cin >> n >> m >> k;
//    for (int i = 0; i <= n; i++)
//        for (int j = 0; j <= m; j++)
//        {
//            dp[i][j] = 0;
//        }
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//        {
//            cin >> a[i][j];
//            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + a[i][j] - dp[i - 1][j - 1];
//        }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
//    bfs(0, 0);
//    cout << ans;
//    return 0;
//}
