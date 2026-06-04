#include<bits/stdc++.h>
using namespace std;

const int MAXN = 50050;
int n, m;
vector<int> graph[MAXN];

vector<int> topological_sort(){
    int degree[MAXN];
    for(int i = 0; i < n; i++) degree[i] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < graph[i].size(); j++){
            int neighbor = graph[i][j];
            degree[neighbor]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> sorting;

    for(int i = 0; i < n; i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }

    if(q.empty()){
        sorting.push_back(-1);
        return sorting;
    }

    while(!q.empty()){
        int current = q.top();
        q.pop();
        sorting.push_back(current);

        for(int neighbor : graph[current]){
            degree[neighbor]--;
            if(degree[neighbor] == 0){
                q.push(neighbor);
            }
        }
    }
    if(sorting.size() == n) return sorting;
    sorting.clear();
    sorting.push_back(-1);
    return sorting;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> sorting = topological_sort();

    for(int item : sorting) {
        if(item == -1) cout << "*" << endl;
        else cout << item << endl;
    }
}
