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
        int n, m, l; 
        string num;
        cin>>num;
        long long sum=0;
        long long ant[num.size()];
        long long bef[num.size()];
        int tam[num.size()]={};
        l=num.size()-1;
        ant[l]=45;
        m=num[l]-'0';
        tam[l]=m+1;
        if(!l){
            cln((m*(m+1))/2);
            continue;
        }
        bef[l]=(m*(m+1))/2;
        long long fact=10;
        df(i, num.size()-2, 0){
            ant[i]=bef[i]=0; m=num[i]-'0';
            uf(j, 0, 10){
                ant[i]+=j*fact+ant[i+1];
                if(j<m) bef[i]+=j*fact+ant[i+1], tam[i]+=fact;
            }
            sum+=ant[i]-ant[i+1];
            fact*=10;
        }
        sum-=ant[0]-ant[1]; n=0;
        sum+=bef[0];
        uf(i, 0, l){ m=num[i]-'0'; sum+=n*tam[i]+bef[i]; n+=m;}
        cln(sum);
    } 
    return 0;
}