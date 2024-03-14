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
        int n, men;
        cin>>n;
        men=n;
        int num[n];
        bool res=true;
        uf(i, 0, n){
            cin>>num[i];
            if(num[i]>0) men=min(men, i);
        }
        while(men<n){
            if(num[men]<0) res=false;
            if(num[men]){
                if(men>=n-2) res=false;
                else{
                    num[men+1]-=2*num[men], num[men+2]-=num[men];
                    num[men]=0;
                } 
            }
            men++;
        }
        (res)? cln("YES"):cln("NO");
    }
    return 0;
}