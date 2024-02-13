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
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

__gnu_pbds::tree<int, __gnu_pbds::null_type, greater<int>, __gnu_pbds::rb_tree_tag,
 __gnu_pbds::tree_order_statistics_node_update> ost; //ordered set





int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int v, e;
        cin>>v>>e;
        int a, b, c;
        ll m;
        vector<vector<int>> mat;
        mat.assign(v, vector<int>(v, 0)); 
        vector<int> fact(v);
        vector<vector<ll>> dist(v);
        while(e--){
            cin>>a>>b>>c;
            a--, b--;
            mat[a][b]=mat[b][a]=c;
        }
        uf(i, 0, v){
            cin>>fact[i]; dist[i].assign(1002, 1e18);
        }
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> cola;
        dist[0][fact[0]]=0;
        cola.push({0, 0, fact[0]});
        while(!cola.empty()){
            vector<ll> padre=cola.top(); cola.pop();
            if(padre[0]>dist[padre[1]][padre[2]]) continue;
            uf(hijo, 0, v){
                m=min(padre[2], 1LL*fact[hijo]);
                if(mat[padre[1]][hijo] && dist[hijo][m]>(dist[padre[1]][padre[2]]+mat[padre[1]][hijo]*padre[2])){
                    dist[hijo][m]=dist[padre[1]][padre[2]]+mat[padre[1]][hijo]*padre[2];
                    cola.push({dist[hijo][m], hijo, m});
                }
            }
        }
        m=1e18;
        uf(i, 1, 1001){
            m=min(m, dist[v-1][i]);
        }
        cln(m);
    }    
    return 0;
}