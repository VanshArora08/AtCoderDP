#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

ll solve(int ind, int ts, vector<pair<int, ll>> p, vector<vector<ll>> &dp)
{
    // cout << ind << " " << ts << endl;
    if (ind == 0)
    {
        if (p[0].first <= ts)
        {
            // cout << p[0].second << " returned " << endl;
            return p[0].second;
        }
        else
            return 0;
    }

    if (dp[ind][ts] != -1)
        return dp[ind][ts];

    ll pick = INT_MIN; // 0
    if (p[ind].first <= ts)
    {
        pick = p[ind].second + solve(ind - 1, ts - p[ind].first, p, dp); // 3,4
        // cout << pick << " picked for " << ind << " " << ts << endl;
    }
    ll notPick = solve(ind - 1, ts, p, dp);

    ll ans = max(pick, notPick);
    dp[ind][ts] = ans;
    return ans;
}

int main()
{
    FastIO;
    int n, sw;
    cin >> n >> sw;
    vector<pair<int, ll>> p;
    for (int i = 0; i < n; i++)
    {
        int w;
        ll v;
        cin >> w >> v;
        p.push_back(make_pair(w, v));
    }

    vector<vector<ll>> dp(n, vector<ll>(sw + 1, -1));

    cout << solve(n - 1, sw, p, dp);

    return 0;
}