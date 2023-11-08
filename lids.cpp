#include<bits/stdc++.h>
using namespace std;
#define int long long
#define deb(x) cout<<#x	<< x	
#define w(x) while(x--)
#define fo(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<pair<int,int>>
#define vvp vector<vector<pair<int,int>>>
bool sortbysec(pair<int,int> &a,pair<int,int>&b){
return(a.second<b.second);}
class DSU {
public:
    vector<int> Parent, Rank;
    DSU(int n) {
    Parent.resize(n); 
    Rank.resize(n, 0);
    for (int i = 0; i < n; i++) Parent[i] = i;
    }
    int Find(int x) {
        return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
    }
    bool Union(int x, int y) {
            int xset = Find(x), yset = Find(y);
            if (xset != yset) {
                Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
                Rank[xset] += Rank[xset] == Rank[yset];
                return true;
            }
        return false;
    }
};
string temp;
int dp[20][10][20][2];

int rec(int pos, prev,int len, bool flag)
{
    if(pos >= temp.size())
    {
        if(len <= 0) return 1;
        return 0;
    }
    char limit = flag?temp[pos]:'9';
    int res = 0;
    if(perv >= 0&&dp[pos][prev][len][flag]!= -1) return dp[pos][prev][len][flag];
    for(char ch = '0' ; ch <= limit; ch++)
    {
        res += rec(pos + 1, ch - '0', max(0*1LL,len - 1),  flag & ch == limit);
    }
    if(prev < 0) return res;
    return dp[pos][prev][len][flag]=res;
}
void solve()
{
    int x, y; 
    cin>> x >> y;
    x--;
    temp = to_string(x);
    string s = to_string(y);
    int curr_num = 0;
    for(int i = 0; i < min(9,s.size()); i++)
    {
        curr_num = (curr_num * 10) + (i + 1);
    }
    int len = 0;
    if(curr_num <= y) len = min(9, s.size());
    else len = s.size() - 1;

    memset(dp, -1 , sizeof(dp));
    int res1 = rec(0,-1,len, 1);
    temp = to_string(y);
    memset(dp, -1 , sizeof(dp));
    int res2 = rec(0,-1,len, 1);

    cout << res2 - res1 << endl;
    return ;
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

int t;cin>>t;w(t){
solve();
}
return 0;
}