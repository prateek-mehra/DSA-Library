// Resize edge-weight pair array by 2*n, input them and source and target. Pass distance vector by reference to dijkstra, also source vertex and number of nodes. Assignment 1e9 distance to every node from source. Assign 0 to source in d vector and priority queue. Until queue is empty, go through every adjacent node of top vertex and see if d[to]>d[v]+weight and accordingly update value and push in pq(vertex,distance).

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
vector<vector<pair<int, int>>> adj;

void dijkstra(int so, vector<int> &d, int n)
{
	d.assign(n, 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({0, so});
	d[so] = 0;
	while (!pq.empty())
	{
		pii p = pq.top();
		pq.pop();
		int dist = p.first;
		int v = p.second;
		if (d[v] != dist)
			continue;

		for (auto edge : adj[v])
		{
			int to = edge.first;
			int weight = edge.second;

			if (weight + d[v] < d[to])
			{
				d[to] = weight + d[v];
				pq.push({d[to], to});
			}
		}
	}
}

int32_t main()
{
	// boost
	int t = 1;
	//  cin>>t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		adj.clear();
		adj.resize(2 * n);
		for (int i = 0; i < m; i++)
		{
			int x, y, c;
			cin >> x >> y >> c;
			// debug1(m);
			adj[x].pb(mp(y, c));
		}
		int so, ta;
		cin >> so >> ta;
		vector<int> d(n + 1);
		dijkstra(so, d, n + 1);
		if (d[ta] == 1e9)
		{
			cout << "-1" << endl;
		}
		else
			cout << d[ta] << endl;
	}
}
