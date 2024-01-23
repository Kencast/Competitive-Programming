#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1920/problem/C

#define uf(i, a, b) for(int i=(a); i<(b); i++)
#define df(i, a, b) for(int i=(a); i>=(b); i--)
#define cln(v) cout<<v<<'\n';
#define ce(v) cout<<v<<' ';
#define ln cout<<'\n';
typedef long long ll;
typedef unsigned long long ull;

int solve(int k, int n, int num[]){
    int g=0;
    for(int i=0; i+k<n; i++){
        g=__gcd(g, abs(num[i+k]-num[i]));
    }
    return g!=1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, n, cont;
    cin>>t;
    while(t--){
        cin>>n;
        int num[n];
        cont=0;
        uf(i, 0, n){
            cin>>num[i];
        }
        int i=1;
        while(i*i<=n){
            if(n%i==0){
                cont+=solve(i, n, num);
                if(n/i!=i) cont+=solve(n/i, n, num);
            }
            i++;
        }
        cln(cont);
    }
    return 0;
}
