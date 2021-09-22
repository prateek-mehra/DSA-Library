/*
Use dijkstra 2 times. Once with C as origin and another
with D as origin. Now for every node, you have the length of the shortest path from
C and from D. Now you can just iterate over each road and check if this road
helps you decreasing the existing distance between C and D.
whenever you get a better answer, you can update your answer to this
value and keep iterating on the auxillary roads.
*/

vector<pair<int, int>> adj[100005];
#define pii pair<int, int>

void dijkstra(int so, vector<int> &d, int n)
{
	d.clear();
	d.resize(n + 1);
	d.assign(n + 1, 1e9);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	d[so] = 0;
	pq.push({0, so});

	while (!pq.empty())
	{

		auto curr = pq.top();
		pq.pop();
		int vertex = curr.second;
		int dist = curr.first;

		if (dist > d[vertex])
		{
			continue;
		}

		for (auto edge : adj[vertex])
		{
			int to = edge.first;
			int cost = edge.second;

			if (cost + dist < d[to])
			{
				d[to] = cost + dist;
				pq.push({d[to], to});
			}
		}
	}
}

int Solution::solve(int A, vector<vector<int>> &B, int C, int D, vector<vector<int>> &E)
{

	for (int i = 0; i < 100005; i++)
	{
		adj[i].clear();
	}

	for (int i = 0; i < B.size(); i++)
	{
		adj[B[i][0]].push_back({B[i][1], B[i][2]});
	}

	vector<int> distFromC, distFromD;

	dijkstra(C, distFromC, A);

	for (int i = 0; i < 100005; i++)
	{
		adj[i].clear();
	}
	for (int i = 0; i < B.size(); i++)
	{
		adj[B[i][1]].push_back({B[i][0], B[i][2]});
	}

	dijkstra(D, distFromD, A);

	if (distFromC[D] == 1e9 && E.size() == 0)
	{
		return -1;
	}

	int ans = distFromC[D];

	for (int i = 0; i < E.size(); i++)
	{
		ans = min(ans, distFromC[E[i][0]] + distFromD[E[i][1]] + E[i][2]);
		ans = min(ans, distFromC[E[i][1]] + distFromD[E[i][0]] + E[i][2]);
	}

	if (ans == 1e9)
		return -1;

	return ans;
}
