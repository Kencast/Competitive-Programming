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
    int t;
    cin>>t;
    while(t--){
        int n, res, p;
        cin>>n;
        res=n;
        vector<int> num(n);
        map<int, int> mapa;
        uf(i, 0, n){
            cin>>num[i];
            mapa[num[i]]+=1;
        }
        for(int a: num){
            n=mapa[a^INT32_MAX];
            p=mapa[a];
            if(p && n){
                res-=min(n, p);
                mapa[a]=mapa[a^INT32_MAX]=0;
            }
        }
        cln(res);
    } 
    return 0;
}