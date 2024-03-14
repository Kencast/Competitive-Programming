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

const int N = 400000;  
ll arbol[N+1];
int len; // array size 


void construir(){
    int p;
    for(int i=len-1; i>0; i--){
        p=i<<1;
        arbol[i]=min(arbol[p], arbol[p+1]);
    }
}

ll query(int i, int j){
    i+=len;
    j+=len;
    ll minn=INT64_MAX;
    while(i<j){
        if(i&1){
            minn=min(minn, arbol[i]);
            i++;
        }
        if(j&1){
            j--;
            minn=min(minn, arbol[j]);
        }
        i>>=1; j>>=1;
    }
    return minn;
}
  

void update(int i, ll num){
    int p;
    i+=len;
    arbol[i]+=num;
    while(i>1){
        i>>=1;
        p=i<<1;
        arbol[i]=min(arbol[p], arbol[p+1]);
    }
}

ll calcRow(int d){
    for(int i=len-2; i>=0; i--){
        update(i, query(i+1, min(len, i+d)));
    }
    return arbol[len];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    int n, m, k, d;
    while(t--){
        cin>>n>>m>>k>>d;
        len=m;
        ll acum[n+1];
        ll res=INT64_MAX;
        acum[0]=0;
        uf(i, 0, n){
            uf(j, 0, m) cin>>arbol[len+j], arbol[len+j]++;
            construir();
            acum[i+1]=calcRow(d+2)+acum[i];
        }
        k--;
        uf(i, 1, n-k+1) res=min(res, acum[i+k]-acum[i-1]);
        cln(res);
    }
    return 0;
}