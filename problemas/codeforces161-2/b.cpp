#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1922/problem/B

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
        int num;
        int cont[n+1]={};
        for(int i=1; i<=n; i++){
            cin>>num;
            cont[num]++;
        }
        ll res=0, cant=0;
        for(ll i: cont){
            res+=(i*(i-1)*(i-2))/6LL;
            res+=(i*(i-1)*cant)/2LL;
            cant+=i;
        }
        cout<<res<<'\n';
    }   
    return 0;
}
