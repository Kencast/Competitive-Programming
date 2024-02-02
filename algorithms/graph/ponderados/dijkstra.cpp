#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;
typedef list<pr> lpr; 

// O((v+e)* log v)

vector<lpr> mat;
vector<int> dist;

void dijkstra(int v, int s){ //s=source
    priority_queue<pr> cola;
    dist[s]=0;
    cola.push({0, s});
    while(!cola.empty()){
        pr padre=cola.top(); cola.pop();
        for(pr hijo: mat[padre.second]){
            if(dist[hijo.second]>dist[padre.second]+hijo.first){
                dist[hijo.second]=dist[padre.second]+hijo.first;
                cola.push({dist[hijo.second], hijo.second});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int v, e, s;
    cin>>v>>e>>s;
    lpr l;
    mat.assign(v, l);
    dist.assign(v, INT32_MAX);
    int i, j, c;
    while(e--){ // nodes from 0 to n-1
        cin>>i>>j>>c;
        mat[i].push_back({c, j}); 
        mat[j].push_back({c, i}); // if it's undirected
    }
    dijkstra(v, s);
    return 0;
}
