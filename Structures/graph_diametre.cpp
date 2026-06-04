#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
vector<int> graph[MAXN];
int dist[MAXN];
bool mark[MAXN];
int n;

void dfs(int current){
    mark[current] = true;
    for(int i = 0; i < graph[current].size(); i++){
        int neighbor = graph[current][i];
        if(!mark[neighbor]){
            dist[neighbor] = dist[current] + 1;
            dfs(neighbor);
        }
    }
}

int get_farthest(int node){
    memset(dist, 0, sizeof dist);
    memset(mark, 0, sizeof mark);
    int max_dist = -1;
    int farthest = 0;

    dist[node] = 0;
    dfs(node);

    for(int i = 1; i <= n; i++){
        if(dist[i] > max_dist){
            max_dist = dist[i];
            farthest = i;
        }
    }
    return farthest;

}

int diametre(){
    int A = get_farthest(1);
    int B = get_farthest(A);
    return dist[B];
}

int main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int v,u; cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    int res = diametre();

    cout << res;
}
