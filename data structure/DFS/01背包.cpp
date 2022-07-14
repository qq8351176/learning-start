#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10010;
int n, v, maxvalue;
int w[N], c[N];
void dfs(int index, int sumw, int sumc)
{
    if (index == n)
    {
        if (sumw <= v)
        {
            maxvalue = max(maxvalue, sumc);
        }
        return;
    }
    dfs(index + 1, sumw, sumc);
    dfs(index + 1, sumw + w[index], sumc + c[index]);
}
int main()
{
    cin >> n >> v;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> c[i];
    }
    dfs(0, 0, 0); //开始时对第1件物品进行选择，此时背包重量0价值也是0
    cout << maxvalue << endl;
    return 0;
}
