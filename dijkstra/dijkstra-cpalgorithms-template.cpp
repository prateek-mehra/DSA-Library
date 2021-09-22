void clr(auto &a,int n){
  a.clear();
  a.resize(n);
}
 
void unq(auto &a){
  sort(all(a));
  a.resize(unique(all(a))-a.begin());
}
 
const int N=200005;
 
vector<vector<int>>adj;
 
const ll INF = 1e9;
void dijkstra(int s, vector<ll> & d,int n) {
  d.assign(n, INF);
 
  d[s] = 0;
  using pii = pair<int, int>;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  while (!q.empty()) {
    int v = q.top().second;
    int d_v = q.top().first;
    q.pop();
    if (d_v != d[v])
      continue;
 
    for (auto edge : adj[v]) {
      int to = edge;
      int len = 1;
 
      if (d[v] + len < d[to]) {
	d[to] = d[v] + len;
	q.push({d[to], to});
      }
    }
  }
}
 
