#include <bits/stdc++.h>
using namespace std;

https://codeforces.com/contest/1921/problem/C

#define uf(i, a, b) for(int i=(a); i<(b); i++)
#define df(i, a, b) for(int i=(a); i>=(b); i--)
#define cln(v) cout<<v<<'\n';
#define ce(v) cout<<v<<' ';
#define ln cout<<'\n';
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        ll carga, minuto, apagar;
        cin>>n>>carga>>minuto>>apagar;
        ll mayor=carga, ant=0, num;
        for(int i=0; i<n; i++){
            cin>>num;
            mayor-=min((num-ant)*minuto, apagar);
            ant=num;
        }
        (mayor>0)? cout<<"YES\n":cout<<"NO\n";
    }   
    return 0;
}
