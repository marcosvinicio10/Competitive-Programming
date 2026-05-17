#include <bits/stdc++.h>
using namespace std;
// Questão 3 - Dieta

int main(){
    int n,m; cin >> n >> m;
    int total = 0;
    for(int i = 0; i < n; i++){
        int p,g,c; cin >> p >> g >> c;
        total += p*4 + g*9 + c*4;
    }
    if(m - total < 0) cout << 0;
    else cout << m - total;


    return 0;
}