const int INF = 1e9;

void dijkstra(int so, vector<int>&d, int n){
  priority_queue<pair<int,int>,vector<pair<int,int>,greater<pair<int,int>>pq;
  d.assign(n, INF);
  d[so] = 0;
  pq.push({0,so});
  
  while(!pq.empty()){
    pair<int,int>top = pq.top();
    pq.pop();
    int dist = top.first;
    int vertex = top.second;
    if(dist != d[vertex]){
      continue;
    }
    
    for(auto edge : g[vertex]){
      int to = edge.first;
      int cost = edge.second;
      
      if(d[vertex] + cost < d[to]){
      d[to] = d[vertex] + cost;
      pq.push({d[to],to});
      }
    }
  }
}
