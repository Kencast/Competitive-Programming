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
    int n,m,k,size; cin>>n>>m>>k;
    vector<int> packages(n);
    ll suma=0;
    for(int j=0;j<n;j++){
        cin>>size;
        suma+=size;
        packages[j]=size;
    } 
    sort(packages.begin(), packages.end(), greater<int>());
    ull abort=m+k;
    double calculo=0;
    for(int i=0;i<(int)packages.size();i++){
        if(!abort) break;
        calculo+=packages[i];
        abort--;
    } cout<<(calculo*100)/suma<<'\n';
    return 0;

}