#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1918/problem/C

#define uf(i, a, b) for(int i=(a); i<(b); i++)
#define df(i, a, b) for(int i=(a); i>=(b); i--)
#define cln(v) cout<<v<<'\n'
#define ce(v) cout<<v<<' '
#define ln cout<<'\n'
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a, b, r;
        cin>>a>>b>>r;
        int tam=sizeof(ll)*8-1;
        if(a<b) swap(a, b);
        bool f=false;
        ll x=0, men=a-b, y;
        df(i, tam, 0){
            if(((a>>i)&1)==0 || ((b>>i)&1)==1) continue;
            if(f==false){
                f=true; continue;
            }
            y=x+(1LL<<i);
            if(y<=r){
                x=y;
            }
        }
        cln(min(men, abs((a^x)-(b^x))));
    }    
    return 0;
}