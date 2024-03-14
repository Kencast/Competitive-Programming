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

int t;

int eulerTotient(int n){
    int res=n, aux=n;
    int r=2;
    while(r*r<=n){
        if(aux%r==0) res/=r, res*=r-1;
        while(aux%r==0) aux/=r;
        r+=1+(r!=2);
    }
    return (res==n)? res-1:res;
}

ll expo(ll base, ll n, ll mod){
    if(!n) return 1LL;
    ll r=expo(base, n/2, mod);
    r=(r*r)%mod;
    if(n%2) r=(r*base)%mod;
    return r;
}

int solve(int b, int m){
    if(b==1) return 1LL;
    return expo(b, solve(b-1, m), 208)+208;
}

// a^p=a^(b)


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll b, m;
    cin>>b>>m;
    if(m==1){
        cln((0)); 
        return 0;
    }
    t=eulerTotient(m);
    cln(expo(b, solve(b-1, m), m));
    return 0;
}

//p=5^262144
//(6^p)%m= (6^b)%m
