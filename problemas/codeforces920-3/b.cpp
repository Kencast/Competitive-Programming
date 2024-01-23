#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1921/problem/B

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
        cin>>n;
        string b, f;
        int cont=0, cont2=0;
        cin>>b;
        cin>>f;
        for(int i=0; i<n; i++){
            if(b[i]=='1' && f[i]=='0') cont++;
            else if(b[i]=='0' && f[i]=='1') cont2++;
        }
        cout<<min(cont, cont2)+abs(cont-cont2)<<'\n';
    }   
    return 0;
}
