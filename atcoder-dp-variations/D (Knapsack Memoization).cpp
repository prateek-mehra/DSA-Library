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
int n, W;
int w[101], v[101];
int dp[100001][101];
int knapsack(int remw, int numitem)
{
	if (remw == 0 || numitem == 0)
	{
		return 0;
	}
	if (dp[remw][numitem] != -1)
	{
		return dp[remw][numitem];
	}
	if (w[numitem - 1] <= remw)
	{
		return dp[remw][numitem] = max(v[numitem - 1] + knapsack(remw - w[numitem - 1], numitem - 1), knapsack(remw, numitem - 1));
	}
	else if (w[numitem - 1] > remw)
	{
		return dp[remw][numitem] = knapsack(remw, numitem - 1);
	}
}
int32_t main()
{
	// boost
	int t = 1;
	// cin>>t;
	while (t--)
	{

		cin >> n >> W;
		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < n; i++)
		{
			cin >> w[i] >> v[i];
		}
		cout << knapsack(W, n);
	}
}
