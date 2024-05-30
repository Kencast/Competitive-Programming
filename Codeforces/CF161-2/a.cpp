#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1922/problem/A

#define uf(i, a, b) for(int i=(a); i<(b); i++)
#define df(i, a, b) for(int i=(a); i>=(b); i--)
#define cln(v) cout<<v<<'\n';
#define ce(v) cout<<v<<' ';
#define ln cout<<'\n';
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, cont=0;
        cin>>n;
        string a, b, c;
        cin>>a>>b>>c;
        for(int i=0; i<n; i++){
            if(c[i]==a[i] || c[i]==b[i]) cont++;
        }
        if(cont==n) cout<<"NO\n";
        else cout<<"YES\n";
    }   
    return 0;
}
