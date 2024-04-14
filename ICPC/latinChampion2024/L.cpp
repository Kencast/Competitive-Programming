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
    int r, c, k;
    char l;
    bool p;
    cin>>r>>c>>k;
    uf(i, 0, r){
        p=false;
        uf(i, 0, c){
            cin>>l;
            if(l=='-') p=true;
        }
        uf(i, 0, k){
            cin>>l;
            if(l=='*' && p){
                cln('N');
                return 0;
            }
        }
    }
    cln('Y');
    return 0;
}