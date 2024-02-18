#include <bits/stdc++.h>
using namespace std;

#define uf(i, a, b) for(int i=(a); i<(b); i++)
#define df(i, a, b) for(int i=(a); i>=(b); i--)
#define cln(v) cout<<v<<'\n'
#define ce(v) cout<<v<<' '
#define ln cout<<'\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pr;
typedef list<pr> lpr;

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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    a--, b--;
    lpr z;
    mat.assign(n, z);
    dist.assign(n, INT32_MAX);
    int num[3];
    long long sum=0;
    uf(i, 0, m){
        cin>>num[0]>>num[1]>>num[2];
        num[0]--, num[1]--;
        mat[num[0]].push_back({num[2], num[1]});
        mat[num[1]].push_back({num[2], num[0]});
        sum+=num[2];
    }
    dijkstra(n, a);
    queue<pr> pila;
    pila.push({b, 0});
    bool vis[n]={};
    vis[b]=true;
    while(!pila.empty()){
        pr nod=pila.front(); pila.pop();
        if(nod.first==a){
            if(nod.second==dist[b]) sum-=nod.second;
            continue;
        }
        for(pr c: mat[nod.first]){
            if(dist[c.second]+nod.second+c.first==dist[b]){
                if(vis[c.second]) sum-=nod.second+c.first;
                else pila.push({c.second, nod.second+c.first}), vis[c.second]=true;
            }
        }
    }
    cln(sum);
    return 0;
}