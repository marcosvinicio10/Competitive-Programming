#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int INF = 1e8;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pii>> graph(n+2);
    vector<int> dist(n+2, INF);
    vector<bool> mark(n+2, false);

    for(int i = 0; i < m; i++){
        int u,v,w; cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,0});
    dist[0] = 0;
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(mark[u]) continue;
        mark[u] = true;
        for(int i = 0; i < graph[u].size(); i++){
            int neighbor = graph[u][i].first;
            int w = graph[u][i].second;
            if(dist[neighbor] > d + w){
                dist[neighbor] = d + w;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    cout << dist[n+1];


}
