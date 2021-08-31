#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long int
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define endl '\n'
#define boost                    \
	ios::sync_with_stdio(false); \
	cin.tie(0);                  \
	cout.tie(0);
#define file                          \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define N 2005
#define mod 1000000007
#define inf 1e17
#define pf push_front
#define pob pop_back
#define pof pop_front
#define debug1(x) cout << #x << " " << x << endl;
#define debug2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define debug3(x, y, z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;

int32_t main()
{
	// boost
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int dp[n + 1];
		memset(dp, 0, sizeof(dp));
		dp[0] = 0;
		dp[1] = abs(a[1] - a[0]);
		if (n > 2)
		{
			for (int i = 2; i < n; i++)
			{
				dp[i] = min(abs(a[i] - a[i - 1]) + dp[i - 1], abs(a[i] - a[i - 2]) + dp[i - 2]);
			}
		}
		cout << dp[n - 1];
	}
}
