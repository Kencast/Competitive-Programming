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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, d=2;
    cin>>n;
    ll div[2];
    int cont[]={0, 0};
    int c=0;
    while(d*d<=n && c<3){
        if(n%d==0){
            div[c]=d; c++;
        }
        while(n%d==0) n/=d, cont[c-1]++;
        d++;
    }
    if((c==1 && cont[0]%2) || div[0]*div[1]==n) cln('Y');
    else if(!c && n>=2) cln('Y');
    else cln('N');
    return 0;
}