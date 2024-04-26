#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> stones(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
    }
    int a, b, c;
    a = 0;
    b = abs(stones[n - 2] - stones[n - 1]);
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n==2)
    {
        cout<<b<<endl;
        return 0;
    }

    for (int i = n - 3; i >= 0; i--)
    {
        int c1 = abs(stones[i] - stones[i + 1]) + b;
        int c2 = abs(stones[i] - stones[i + 2]) + a;
        c = min(c1, c2);
        a = b;
        b = c;
    }
    cout << c << endl;
    return 0;
}