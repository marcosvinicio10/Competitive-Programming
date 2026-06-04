#include<bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
 
const int MAXN = 300005;
int v[MAXN];
 
struct SegTree
{
    int tree[4 * MAXN];
 
    int join(int a, int b){
        return a + b;
    }
 
    void build(int node, int tl, int tr){
        if(tl == tr){
            tree[node] = v[tl];
            return;
        }
        int mid = (tl+tr)/2;
        build(node*2, tl, mid);
        build(node*2+1, mid+1, tr);
        tree[node] = join(tree[node*2], tree[node*2+1]);
    }
    void update(int node, int tl, int tr, int pos, int val){
        if(tl == tr){
            v[pos] = val;
            tree[node] = val;
            return;
        }
        int mid = (tl+tr)/2;
        if(pos > mid){
            update(node*2+1, mid+1, tr, pos, val);
        } else update(node*2, tl, mid, pos, val);
        tree[node] = join(tree[node*2+1], tree[node*2]);
    }
    int query(int node, int tl, int tr, int open, int end){
        int mid = (tl+tr)/2;
        if(tl > end || tr < open) return 0;
        if(tl>=open && tr<=end){
            return tree[node];
        } else {
            return join(query(node*2,tl, mid, open, end), query(node*2+1,mid+1, tr, open, end));
        }
    }
}seq;
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,q; cin >> n >> q;
    vector<int> ans;
    for(int i = 1; i <= n; i++) cin >> v[i];
    seq.build(1,1,n);
    for(int i = 0; i < q; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) seq.update(1,1,n,b,c);
        if(a == 2) ans.push_back(seq.query(1,1,n,b,c));
    }
    for(int item : ans) cout << item << endl;
}
