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

int n;
ll inf=100000000;
//ll memo[1000001][3];
vector<int> tipo;
vector<ll> cant;

// ll solve(int word, int cantC){
//     if(cantC>2) return inf;
//     if(word>=n) return 0;
//     if(memo[word][cantC]>0) return memo[word][cantC];
//     if(tipo[word]==0) return memo[word][cantC]=1+solve(word+1, cantC+1);
//     if(cant[word]==1) return memo[word][cantC]=1+solve(word+1, 0);
//     return memo[word][cantC]=min(cant[word]+solve(word+1, 0), 1+solve(word+1, cantC+1));
// }

ll solve(){
    ll mem[n+1][4];
    uf(i, 0, n+1) mem[i][3]=inf;
    uf(i, 0, 3) mem[n][i]=0;
    df(i, n-1, 0){
        uf(j, 0, 3){
            mem[i][j]=inf;
            if(tipo[i]) mem[i][j]=cant[i]+mem[i+1][0];
            if(tipo[i]==0 || cant[i]>1) mem[i][j]=min(mem[i][j], 1+mem[i+1][j+1]);
        }
    }
    return mem[0][0];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n; 
    tipo.reserve(n);
    cant.reserve(n);
    string s;
    int tam, pos;
    char v[6]={'A', 'E', 'I', 'O', 'U', 'Y'};
    uf(i, 0, n){
        cin>>s;
        pos=0;
        tam=min(3, (int)s.size());
        uf(j, 0, tam){
            uf(p, 0, 6){
                if(v[p]==s[j]) pos=j+1;
            }
            if(pos) break;
        }
        if(pos) tipo[i]=1, cant[i]=pos;
        else tipo[i]=0, cant[i]=1;
    }
    //solve(0, 0);
    //(memo[0][0]>=inf)? cln('*'): cln(memo[0][0]);
    ll res=solve();
    (res>=inf)? cln("*"): cln(res);
    return 0;
}