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
        int n, k;
        cin>>n>>k;
        int res[n+1]={};
        int l=1, r=n;
        uf(i, 1, k+1){
            for(int j=i; j<=n; j+=k){
                if(j&1) res[j]=l++;
                else res[j]=r--; 
            }
        }
        uf(p, 1, n) ce(res[p]);
        cln(res[n]);
    }    
    return 0;
}