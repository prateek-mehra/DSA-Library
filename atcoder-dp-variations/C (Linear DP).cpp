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
		int a[n][3];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		int res[n][3];
		res[0][0] = a[0][0];
		res[0][1] = a[0][1];
		res[0][2] = a[0][2];
		for (int i = 1; i < n; i++)
		{
			res[i][0] = max(res[i - 1][1] + a[i][0], res[i - 1][2] + a[i][0]);
			res[i][1] = max(res[i - 1][0] + a[i][1], res[i - 1][2] + a[i][1]);
			res[i][2] = max(res[i - 1][1] + a[i][2], res[i - 1][0] + a[i][2]);
		}
		cout << max(res[n - 1][0], max(res[n - 1][1], res[n - 1][2]));
	}
}
