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
int dp[20][200][2];
int rec(int pos, int curr,  bool tight)
{
    if(pos >= temp.size())
    {
        return curr;
    }
    char limit = tight ? temp[pos]: '9';
     if(dp[pos][curr][tight] != -1) return dp[pos][curr][tight];
    int res = 0;
    //  cout << limit  << endl;
    for(char ch = '0'; ch <= limit; ch++){

            res += rec(pos + 1, curr + (ch - '0'), tight & (ch == limit));
    }
    return dp[pos][curr][tight] = res;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    int res1  = 0;
    if(a > 0)
    {
        temp = to_string(a - 1);
        memset(dp, -1 , sizeof(dp));
        res1 = rec(0, 0, 1);
    }

    temp = to_string(b);
    memset(dp, -1 , sizeof(dp));
    int res = rec(0, 0, 1) - res1;

     cout << res << endl;
    

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