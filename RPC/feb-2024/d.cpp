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
    int t, a, b;
    int let[26];
    char l[]={'A', 'T', 'G', 'C'};
    string s;
    cin>>s;
    cin>>t;
    uf(i, 0, 4) let[l[i]-'A']=i;
    int num[4][s.size()+1];
    uf(i, 0, 4) num[i][0]=0;
    uf(i, 0, s.size()){
        a=let[s[i]-'A'];
        uf(j, 0, 4) num[j][i+1]=num[j][i]+(j==a);
    }
    while(t--){
        cin>>a>>b;
        int p[6]={};
        uf(i, 0, 4){
            p[5]=-1;
            uf(j, 0, 4) {
                if(p[j]==0 && (num[j][b]-num[j][a-1])>p[5]) p[4]=j, p[5]=num[j][b]-num[j][a-1];
            }
            p[p[4]]=1;
            cout<<l[p[4]];
        }
        ln;
    }
    return 0;
}