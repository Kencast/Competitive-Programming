#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1925/problem/A

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
        int n, k;
        cin>>n>>k;
        string res="a";
        for(int i=1; i<k; i++){
            res+=char ('a'+i);
        }
        cout<<res;
        for(int i=1; i<n; i++) cout<<res;
        ln;
    }
    return 0;
}