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
    int n, m;
    char l;
    cin>>n>>m;
    int cont[m][26];
    for(int i=0; i<m; i++){
        for(int j=0; j<26; j++) cont[i][j]=0;
    }
    char res[m];
    for(int i=0; i<m; i++) res[i]='a';
    while(n--){
        for(int i=0; i<m; i++){
            cin>>l;
            cont[i][l-'a']++;
            if(cont[i][l-'a']==cont[i][res[i]-'a']) res[i]=min(l,res[i]);
            if(cont[i][l-'a']>cont[i][res[i]-'a']) res[i]=l;
            
        }
    }
    for(int i=0; i<m; i++) cout<<res[i];
    ln;
    return 0;
}