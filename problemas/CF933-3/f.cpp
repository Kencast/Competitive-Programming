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
    int n, m, k;
    int mid[3];
    int ind;
    while(t--){
        cin>>n>>m>>k;
        int num[n];
        int model[m];
        vector<int> f(k);
        cin>>num[0];
        mid[0]=0;
        uf(i, 1, n){
            cin>>num[i];
            if((num[i]-num[i-1])>=mid[0]){
                mid[0]=num[i]-num[i-1];
                ind=i;
            }
        }
        mid[2]=(num[ind]+num[ind-1])/2;
        uf(i, 0, m) cin>>model[i];
        uf(i, 0, k) cin>>f[i];
        sort(f.begin(), f.end());
        int res=mid[0];
        uf(i, 0, m){
            int inf=0, sup=k-1, m;
            while(inf+1<sup){
                m=(inf+sup)/2;
                if(model[i]+f[m]<=mid[2]) inf=m;
                else sup=m;
            }
            res=min(res, max(abs(num[ind]-model[i]-f[inf]), abs(model[i]+f[inf]-num[ind-1])));
            res=min(res, max(abs(num[ind]-model[i]-f[sup]), abs(model[i]+f[sup]-num[ind-1])));
        }
        uf(i, 1, n) if(i!=ind)res=max(res, num[i]-num[i-1]);
        cln(res);
    } 
    return 0;
}