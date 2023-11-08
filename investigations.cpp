#include<bits/stdc++.h>
using namespace std;
#define int long long


int dp[20][100][100][2];
string temp;
int k;

int rec(int pos, int curr_sum, int curr_num,  bool tight)
{
    if (pos >= (int) temp.size())
    {
        if (curr_sum % k == 0 && curr_num % k == 0) return 1;
        return false;
    }
    if(dp[pos][curr_num][curr_sum][tight] != -1) return dp[pos][curr_num][curr_sum][tight];

    char limit = tight ? temp[pos] : '9';
    int res = 0;
    for (char ch = '0'; ch <= limit; ch++)
    {
        if (tight && ch == limit)
        {
            res += rec(pos + 1, curr_sum + ch - '0', (curr_num * 10  + ch - '0') % k, true);
        }
        else
        {
            res += rec(pos + 1, curr_sum + ch - '0',(curr_num * 10 + ch - '0') % k, false);
        }
    }
    return dp[pos][curr_num][curr_sum][tight] = res;
}
void solve(int T)
{
    int a, b, c;
    cin >> a >> b >> c;
    k = c;
    if(k >= 100){  cout << "Case " << T << ": " << 0 << endl; return ;}
    
    memset(dp, -1, sizeof(dp));
    
    temp = to_string(a - 1);
    int res1 = rec(0, 0, 0, 1);

    memset(dp, -1, sizeof(dp));
    temp = to_string(b);
    int res2 = rec(0, 0,  0, 1);

    int res = res2 - res1;
    cout << "Case " << T << ": " << res << endl;
    return;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}