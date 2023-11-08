#include <bits/stdc++.h>
using namespace std;
#define int long long

string temp;
int m, d;
int dp[2001][2000][2][2];
int rec(int pos, int curr, bool flag , bool ILZ, int CILZ)
{
    if (pos >= temp.size())
    {
        if (curr % m == 0 && !ILZ){
            return 1;
        }    
        return 0;
    }
    
    if(dp[pos][curr][flag][ILZ] != -1) return dp[pos][curr][flag][ILZ];
    
    char limit = flag ? temp[pos] : '9';
    int res = 0;
    int postion = pos - CILZ;

    if ((postion + 1) % 2 == 0)
    {
        if(d <= (limit - '0') )
        res += rec(pos + 1, ((curr * 10) %m   + d % m ) %m  , flag & (d == (limit - '0')),  ILZ & (d == 0), CILZ + (ILZ & (d == 0)));
    }
    else
    {
        for (char ch = '0'; ch <= limit; ch++)
        {
             if(ch == (d + '0')) continue;
            res += rec(pos + 1, ((curr * 10) %m + ((ch - '0') %m )) %m  , flag & ch == limit, ILZ & (ch == '0') , CILZ + (ILZ & (ch == '0')));
        }
    }

    return dp[pos][curr][flag][ILZ] = res;
}
void solve()
{
    cin >> m >> d;
    string a, b;
    cin >> a >> b;

    temp = a;
    memset(dp, -1, sizeof(dp));
    int res1 = rec(0, 0, 1, 1, 0);
    // cout << res1 << endl;

     temp = b;
     memset(dp, -1, sizeof(dp));
     int res2 = rec(0, 0, 1, 1, 0);
    //  cout << res2 << endl;
    int curr_sum = 0;
    bool flag = true;
    for(int i = 0; i < a.size(); i++)
    {
        if((i + 1) % 2 == 0 and (a[i] - '0') != d ){
            flag = false;break;
        }
        curr_sum = curr_sum * 10 + a[i] - '0';
        curr_sum%=m;
    }
    if(curr_sum == 0){
        res1--;
    }
     cout << res2 - res1 << endl;

    return;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}