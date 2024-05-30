#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1922/problem/C

#define uf(i, a, b) for(int i=(a); i<(b); i++)
#define df(i, a, b) for(int i=(a); i>=(b); i--)
#define cln(v) cout<<v<<'\n';
#define ce(v) cout<<v<<' ';
#define ln cout<<'\n';
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, n, m;
    cin>>t;
    while(t--){
        int x, y;
        cin>>n;
        int city[n+1];
        int right[n+1];
        int left[n+1];
        for(int i=1; i<=n; i++){
            cin>>city[i];
        }
        right[0]=left[0]=0;
        right[1]=left[n]=1;
        right[n]=left[1]=0;
        for(int i=2; i<n; i++){
            (city[i+1]-city[i]<city[i]-city[i-1])? right[i]=1:right[i]=city[i+1]-city[i];
            (city[i]-city[i-1]<city[i+1]-city[i])? left[i]=1:left[i]=city[i]-city[i-1];
            right[i]+=right[i-1];
            left[i]+=left[i-1];
        }
        right[n]+=right[n-1]; left[n]+=left[n-1];
        cin>>m;
        while(m--){
            cin>>x>>y;
            if(y>x) cout<<right[y-1]-right[x-1]<<'\n';
            else cout<<left[x]-left[y]<<'\n';
        }
    }   
    return 0;
}
