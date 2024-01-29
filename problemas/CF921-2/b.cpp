#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1925/problem/B

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
        int x, n, num=2, mayor=1;
        cin>>x>>n;
        if(x%n==0){
            cln(x/n); continue;
        }
        while(num*num<=x){
            if(x%num==0){
                if(x/num>n) mayor=max(mayor, num);
                if(num>n) mayor=max(mayor, x/num);
            }
            num++;
        }
        cln(mayor);
    } 
    return 0;
}