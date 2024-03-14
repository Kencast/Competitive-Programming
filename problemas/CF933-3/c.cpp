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
       int n;
       cin>>n;
       string s;
       cin>>s;
       int cont=0, i=0;
       string a="map-";
       string b="pie-";
       int ap, bp;
        while(s[i]){
            ap=0, bp=0;
            while(s[i]==a[ap]) ap++, i++;
            if(ap==3) cont++, i--;
            while(s[i]==b[bp]) bp++, i++;
            if(bp==3) cont++;
            if(ap==3 && bp==3) cont--; 
            (bp || ap)? i:i++;
        }
       cln(cont);
    }
    return 0;
}