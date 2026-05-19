#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5 + 10;
int parent[MAXN];
int tam[MAXN];

int find(int value){
    if(parent[value] == value) return value;
    return parent[value] = find(parent[value]);
}

void merge(int a, int b){
    int x = find(a);
    int y = find(b);

    if(tam[x] >= tam[y]){
        parent[y] = x;
        tam[x] += tam[y];
    } else {
        parent[x] = y;
        tam[y] += tam[x];
    }
    return;
}

int32_t main(){
    int n,q; cin >> n >> q;
    vector<char> res;

    for(int i = 1; i <= n; i++){
        parent[i] = i;
        tam[i] = 1;
    }

    for(int i = 0; i < q; i++){
        char a; int c,b; cin >> a >> b >> c;
        if(a == 'C'){
            if(find(b) == find(c)){
                res.push_back('S');
            } else res.push_back('N');
        } else merge(b,c);
    }

    for(char item : res) cout << item << endl;

}
