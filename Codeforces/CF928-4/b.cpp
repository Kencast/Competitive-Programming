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
        int n, p;
        char s;
        cin>>n;
        int num[n]={};
        uf(i, 0, n){
            uf(j, 0, n){
                cin>>s; num[i]+=(s=='1');
            }
        }
        p=0;
        while(num[p]==0) p++;
        if(num[p]!=num[p+1]) cln("TRIANGLE");
        else cln("SQUARE");
    } 
    return 0;
}