//Funda: carry over of bits to the final answer, monitored through dp

#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define ms(a) memset(a, 0, sizeof(a));
#define all(a) a.begin(), a.end()
#define endl '\n'
#define boost                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define mod 1000000007
#define inf 1e18
#define deb(x) cout << #x << " " << x << endl;
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define deb3(x, y, z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;

void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int dp[100];
    ms(dp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if ((1LL << j) & a[i])
                dp[j] += 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 99; i++)
    {

        if (i > 0)
        {
            dp[i] += dp[i - 1]>>1;
        }
        if (dp[i])
        {
            ans += (1LL << i);
        }
    }

    cout << ans << endl;
}

signed main()
{
    //boost
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
