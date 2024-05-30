#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1925/problem/C

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
        int n, k, m;
        int p=0, c=0, l;
        cin>>n>>k>>m;
        string s;
        cin>>s;
        vector<int> cont(26, 0);
        string res="";
        while(p<m){
            if(res.size()==n) break;
            l=s[p]-'a';
            c+=cont[l]==0;
            cont[l]++;
            if(c==k){
                res+=s[p];
                cont.assign(26, 0);
                c=0;
            }
            p++;
        }
        if(res.size()==n){
            cln("YES"); continue;
        }
        for(int i=0; i<k; i++){
            if(!cont[i]){
                cln("NO");
                cout<<res+string(n-res.size(), char('a'+i))<<"\n"; break;
            }
        }

    }    
    return 0;
}