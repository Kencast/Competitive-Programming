#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; //destine node and cost
typedef list<pii> edge;
const int Inf=1000000000;

bool bellmanF(int n, vector<edge> adj, int s, int dist[]){
    for (int i = 0; i < n; i++)
    {
        dist[i]=Inf;
    }
    dist[s]=0;
    for (int i = 0; i <n-1; i++) //n-1 times
    {
        bool finish=true; //optimization
        for (int nod = 0; nod <n; nod++) //relax all edges
        {
            if(dist[nod]==Inf) continue; //it doesnt change
            for(pii e: adj[nod]){
                if(dist[nod]+e.second <dist[e.first]){
                    dist[e.first]=dist[nod]+e.second, finish=false;
                } 
            }
        }
        if(finish) break;
    }
    //optional detect negative cycles
    for (int nod = 0; nod <n; nod++)
    {
        if(dist[nod]==Inf) continue;
        for(pii e: adj[nod]){
            if(dist[nod]+e.second <dist[e.first]) return false;
        }
    }
    //return false if has negative cycle, true otherwise
    return true;
}

int main(int argc, char const *argv[])
{
    int v, e, source;
    int a, b, w;
    cin>>v>>e>>source;
    vector<edge> adj(v); //nodos de 0 a v-1
    int dist[v]; //guardar las distancias
    while(e--){
        cin>>a>>b>>w;
        adj[a].push_back({b, w}); //es un grafo dirigido
    }
    bool safe=bellmanF(v, adj, source, dist);
    return 0;
}
