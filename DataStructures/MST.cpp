#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e8 + 10;
vector<array<int, 3>> graph;
int parent[MAXN]; int sz[MAXN]; int n, m; 

int find(int value){
    if(parent[value] == value) return value;
    return parent[value] = find(parent[value]);
}

void merge(int x, int y){
    int a = find(x);
    int b = find(y);

    if(a == b) return;

    if(sz[a] >= sz[b]){
        parent[b] = a;
        sz[a] += sz[b];
    } else {
        parent[a] = b;
        sz[b] += sz[a];
    }
    return;
}

void dsu(){
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        parent[i] = i;
    }
    return;
}

int mst(){
    dsu();
    sort(graph.begin(), graph.end());
    int mst_cost = 0;

    for(int i = 0; i < graph.size(); i++){
        int u = graph[i][1], v = graph[i][2], w = graph[i][0];
        if(find(u) != find(v)){
            merge(u,v);
            mst_cost += w;
        }
    }

    return mst_cost;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        graph.push_back({w,u,v});
    }

    cout << mst();
    
}
