#include <bits/stdc++.h>
using namespace std;

const int INF = 100000;

int main(){
    int n, m; cin >> n >> m;
    int graph[n+1][n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    int res = INF;
    
    for(int i = 1; i <= n; i++){
        int aux = 0;
        for(int j = 1; j <= n; j++){
            aux = max(aux, graph[i][j]);
        }
        res = min(res, aux);
    }

    cout << res;
}
