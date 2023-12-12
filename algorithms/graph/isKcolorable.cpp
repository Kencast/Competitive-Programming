#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;

bool esSeguro(vvi grafo, int color[], int vert, int c){
    for(int i: grafo[vert]){
        if(color[i]==c) return false;
    }
    return true;
}

bool esColoreable(vvi grafo, int cantColores, int color[], int vert){
    if(vert==grafo.size()) return true;
    for(int i=1; i<=cantColores; i++){
        if(esSeguro(grafo, color, vert, i)){
            color[vert]=i;
            if(esColoreable(grafo, cantColores, color, vert+1)) return true;
            color[vert]=0;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n, a, i, j, k;
    cin>>n>>a>>k;
    vvi vecinos(n); //de 0 a n-1
    int color[n]={};
    while(a--){
        cin>>i>>j;
        vecinos[i].push_back(j);
        vecinos[j].push_back(i);
    }
    (esColoreable(vecinos, k, color, 0)==true)? cout<<"true":cout<<"false";
    cout<<'\n';
    return 0;
}
