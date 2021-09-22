class Solution
{
public:
	int reachableNodes(vector<vector<int>> &edges, int M, int n)
	{
		unordered_map<int, unordered_map<int, int>> e;

		for (auto v : edges)
		{
			e[v[0]][v[1]] = e[v[1]][v[0]] = v[2];
		}

		priority_queue<pair<int, int>> pq;
		unordered_map<int, int> seen;
		pq.push({M, 0});

		while (!pq.empty())
		{
			int i = pq.top().second;
			int moves = pq.top().first;
			pq.pop();
			if (!seen.count(i))
			{
				seen[i] = moves;
				for (auto u : e[i])
				{
					int rem = moves - u.second - 1;
					if (!seen.count(u.first) && rem >= 0)
					{
						pq.push({rem, u.first});
					}
				}
			}
		}

		int res = seen.size();

		for (auto v : edges)
		{
			int a = seen.find(v[0]) == seen.end() ? 0 : seen[v[0]];
			int b = seen.find(v[1]) == seen.end() ? 0 : seen[v[1]];
			res += min(v[2], a + b);
		}

		return res;
	}
};
