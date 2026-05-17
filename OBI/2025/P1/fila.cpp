#include <bits/stdc++.h>
using namespace std;

//Questão 4 - Fila

int main(){
    int n; cin >> n;
    int array[n];
    int MAXN = 0;
    int res = 0;
    for(int i = n-1; i >= 0; i--){
        cin >> array[i];
    }
    for(int i = 0; i < n; i++){
        if(array[i] <= MAXN) res++;
        MAXN = max(MAXN, array[i]);
    }
    cout << res;
}