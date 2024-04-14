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


ll eulerTotient(ll n){
    ll res=n;
    ll r=2;
    while(r*r<=n){
        if(n%r==0) res/=r, res*=r-1;
        while(n%r==0) n/=r;
        r+=1+(r!=2);
    }
    return (n>1)? res-=res/n:res;
}

ll expo(ll base, ll n, ll mod){
    if(!n) return 1LL;
    ll r=expo(base, n/2, mod);
    r=(r*r)%mod;
    if(n%2) r=(r*base)%mod;
    return r;
}

ll solve(ll b, ll m){
    if(m==1) return 0;
    if(b<3) return b%m;
    if(b<5) return expo(b, pow(b-1, b-2), m);
    ll tot=eulerTotient(m);
    return expo(b, solve(b-1, tot)+tot, m);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll b, m;
    cin>>b>>m;
    if(m==1){
        cln((0)); 
        return 0;
    }
    cln(solve(b, m));
    return 0;
}

//p=5^262144
//(6^p)%m= (6^b)%m
