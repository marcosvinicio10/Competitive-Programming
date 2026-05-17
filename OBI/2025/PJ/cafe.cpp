#include <bits/stdc++.h>
using namespace std;
// Questão 2 - Cafe com Leite

int main(){
    int a,b,c,d; cin >> a >> b >> c >> d;
    if( a <= c - d && c - d <= b) cout << "S";
    else cout << "N";
    

    return 0;
}