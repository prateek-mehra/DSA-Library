/*
ways[i] - no of ways to reach i
if dist[from] + cost < dist[to] then ways[to] = ways[from]
if dist[from] + cost == dist[to] then ways[to] += ways[from]
*/

class Solution
{
public:
#define ll long long
#define mod 1000000007

	const long long INF = 1e16;

	vector<pair<ll, ll>> adj[201];
	long long ways[201];

	void dijkstra(ll so, vector<int> &d, ll n)
	{
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

		d.assign(n, INF);
		d[so] = 0;
		ways[0] = 1;
		pq.push({0, so});

		while (!pq.empty())
		{
			pair<ll, ll> top = pq.top();
			pq.pop();
			ll dist = top.first;
			ll vertex = top.second;

			if (dist != d[vertex])
			{
				continue;
			}

			for (auto edge : adj[vertex])
			{
				ll to = edge.first;
				ll cost = edge.second;

				if (d[vertex] + cost < d[to])
				{
					d[to] = d[vertex] + cost;
					ways[to] = ways[vertex];
					pq.push({d[to], to});
				}
				else if (d[vertex] + cost == d[to])
				{
					ways[to] = (ways[to] + ways[vertex]) % mod;
				}
			}
		}
	}

	int countPaths(int n, vector<vector<int>> &roads)
	{

		memset(ways, 0, sizeof(ways));
		int m = roads.size();

		for (int i = 0; i < m; i++)
		{
			adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
			adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
		}

		vector<int> d(n + 1);
		dijkstra(0, d, n);

		return ways[n - 1] % mod;
	}
};
