#include <bits/stdc++.h>
using namespace std;

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
    int m, s;
    cin>>m>>s;
    int a[m];
    int b[m];
    if(m==1 && s<10){
        cout<<s<<" "<<s<<'\n'; return 0;
    }
    if(!s || s>9*m){
        cln("-1 -1"); return 0;
    }
    t=s; 
    for(int i=1; i<10; i++) if(t-i<=9*(m-1)) a[0]=i, t-=i, i=10;
    for(int i=1; i<m; i++){
        for(int j=0; j<10; j++)
            if(t-j<=9*(m-i-1)) a[i]=j, t-=j, j=10;
    }
    for(int i=0; i<m; i++) b[i]=min(9, s), s-=b[i];
    for(int c: a) cout<<c;
    cout<<' ';
    for(int c: b) cout<<c;
    ln;
    return 0;
}