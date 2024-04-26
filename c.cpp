#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);


int solve(int ind, int p , vector<vector<int>> &dp, vector<vector<int>> &act ,  int n){
    if(ind==n) return 0;
    if(p!=-1 && dp[ind][p]!=-1)  return dp[ind][p];
    int ans=INT_MIN;
    for(int ch=0;ch<3;ch++){
        if(ch!=p){
            ans=max(ans,(act[ind][ch]+solve(ind+1,ch,dp,act,n)));
        }
    }
    dp[ind][p]=ans;
    return ans;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<vector<int>> act(n,vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> act[i][j];
        }
    }

    vector<vector<int>> dp(n+1,vector<int>(3,-1));
    cout<<solve(0,-1,dp,act,n)<<endl;

    return 0;
}