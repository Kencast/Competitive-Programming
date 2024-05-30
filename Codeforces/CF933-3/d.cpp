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
    int t, c;
    cin>>t;
    int n, m, x;
    char l;
    while(t--){
        cin>>n>>m>>x;
        set<int> conj[2];
        conj[0].insert(x);
        int b=0;
        uf(i, 0, m){
            cin>>x>>l;
            while(!conj[b].empty()){
                c=*conj[b].begin();
                conj[b].erase(c);
                if(l=='0' || l=='?') conj[!b].insert((c+x-1)%n+1);
                if(l=='1' || l=='?') conj[!b].insert((c-x-1+n)%n+1);
            }
            b^=1;
        }
        cln(conj[b].size());
        for(int c: conj[b]) ce(c);
        ln;
    } 
    return 0;
}