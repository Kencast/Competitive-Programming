#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef vector<p> vii;

int prim(vii g[], int n){ //n= cantidad de nodos
    bool vis[n+1];
    for(int i = 0; i <=n; i++) vis[i]=false;
    priority_queue<p, vector<p>, greater<p>> cola;
    p aux;
    int cost=0, aristas=-1;
    cola.push({0, 1}); //first=nodo second=peso
    while(!cola.empty()){
        aux=cola.top(), cola.pop();
        if(!vis[aux.second]){
            vis[aux.second]=true;
            cost+=aux.first, aristas++;
            if(aristas==n-1) return cost;
            for(p hij: g[aux.second]){
                if(!vis[hij.second]) cola.push(hij);
            }
        }
    }
    return cost;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, c; //cantidad de nodos
    cin>>a>>c;
    vii g[a+1];
    while(c--){
        
    }
    cout<<prim(g, a)<<'\n';
    return 0;
}