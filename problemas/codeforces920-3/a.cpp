#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1921/problem/A

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
        int cor[8];
        for(int i=0; i<7; i+=2) cin>>cor[i]>>cor[i+1];
        int x2=INT32_MAX, y2=INT32_MAX;
        for(int i=0; i<7; i+=2){
            cor[0]=max(cor[0], cor[i]); cor[1]=max(cor[1], cor[i+1]);
            x2=min(x2, cor[i]), y2=min(y2, cor[i+1]); 
        }
        cout<<abs((cor[0]-x2)*(cor[1]-y2))<<'\n';
    }   
    return 0;
}
