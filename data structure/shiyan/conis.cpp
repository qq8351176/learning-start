#include <iostream>
#include <vector>
using namespace std;
const int max_coins = 100;
vector<int> coins(max_coins + 1);
vector<int> dp(max_coins + 1);
int find_NUMS=0;
int find_coins(int start, int end)
{   
    find_NUMS++;
    int mid = (end - start + 1) / 2;
    if (end - start == 1)
    {
        if (dp[start] - dp[start - 1])
            return end;
        else
            return start;
    }
    if ((end-start+1) % 2 != 0)//bug
    {
        if (dp[start + mid - 1] - dp[start - 1] == dp[end - 1] - dp[start + mid - 1])
        {
            find_NUMS++;
            return end;
        }
        else if (dp[start + mid - 1] - dp[start - 1] > dp[end - 1] - dp[start + mid - 1])
        {
            return find_coins(start + mid, end - 1);
        }
        else
        {
            return find_coins(start, start + mid - 1);
        }
    }
    else
    {
        if (dp[start + mid - 1] - dp[start - 1] > dp[end] - dp[start + mid - 1])
        {
            return find_coins(start + mid, end);
        }
        else
        {
            return find_coins(start, start + mid - 1);
        }
    }
}
int main()
{
    int size;
    cout << "输入硬币个数";
    cin >> size;
    cout << "输入" << size << "个硬币 0为假币 1为真币" << endl;
    for (int i = 1; i < size + 1; i++)
    {
        cin >> coins[i];
        dp[i] = coins[i] + dp[i - 1];
    }
    
    for (int i = 1; i < size + 1; i++)
        cout << coins[i] << " ";
    cout << endl;
    for (int i = 1; i < size + 1; i++)
        cout << dp[i] << " ";
    cout << endl;
    cout << "假硬币的位置在" << find_coins(1, size)<<endl;
    cout<<"利用二分法查找硬币,查找次数为"<<find_NUMS<<"次"<<endl;
    system("pause");
    
    return 0;
}
