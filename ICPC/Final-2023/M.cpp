#include <bits/stdc++.h>
using namespace std;
#define Inf 1000000010

typedef pair<int, int> nodo;
bool operator<(const nodo& a, const nodo& b){
    return a.first<b.first;
}

class solve{
public:
    vector<nodo> *vecinos;
    int tam;

    solve(int n){
        tam=n;
        vecinos=new vector<nodo>[n];
    }

    void meter(int& i, int& j, int& d){
        vecinos[i].push_back({j, d});
        vecinos[j].push_back({i, d});
    }

    void dijkstra(nodo padre, int dont, int dist[]){
        priority_queue<nodo> cola;
        nodo aux;
        int i;
        cola.push(padre);
        dist[padre.second]=0;
        while(!cola.empty()){
            padre=cola.top(); cola.pop();
            if(padre.second!=dont){
                for(i=0; i<vecinos[padre.second].size(); i++){
                    aux=vecinos[padre.second][i];
                    if(dist[aux.first]>(dist[padre.second]+aux.second)){
                        dist[aux.first]=dist[padre.second]+aux.second;
                        cola.push({dist[aux.first], aux.first});
                    }
                }
            }
        }
    }

};


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, p, g;
    int i, j, d;
    cin>>n>>m;
    cin>>p>>g;
    n++;
    solve ady(n);
    int save[n];
    int newDist[n];
    while(m--){
        cin>>i>>j>>d;
        ady.meter(i, j, d);

    }
    for(m=0; m<n; m++) save[m]=Inf, newDist[m]=Inf;
    ady.dijkstra({0, p}, 0, save);
    ady.dijkstra({0, p}, g, newDist);
    m=save[g]<<1; d=0;
    for(i=1; i<n; i++){
        if(save[i]==m && newDist[i]>save[i]) d++, cout<<i<<' ';
    }
    if(!d) cout<<'*';
    cout<<'\n';
    return 0;
}
