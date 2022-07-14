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
    cout << "����Ӳ�Ҹ���";
    cin >> size;
    cout << "����" << size << "��Ӳ�� 0Ϊ�ٱ� 1Ϊ���" << endl;
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
    cout << "��Ӳ�ҵ�λ����" << find_coins(1, size)<<endl;
    cout<<"���ö��ַ�����Ӳ��,���Ҵ���Ϊ"<<find_NUMS<<"��"<<endl;
    system("pause");
    
    return 0;
}
