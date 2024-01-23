#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1920/problem/B

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, n, may;
    int k, x, p;
    cin>>t;
    while(t--){
        cin>>n>>k>>x;
        vector<int> num(n+1);
        for(int i=1; i<=n; i++) cin>>num[i];
        sort(num.begin(), num.end());
        for(int i=1; i<=n; i++) num[i]+=num[i-1];
        may=-num[n];
        for(int i=n-k+1; i<=n; i++){
            p=max(0, i-x-1);
            may=max(may, num[p]-(num[i-1]-num[p]));
        }
        p=max(0, n-x);
        may=max(may, num[p]-(num[n]-num[p]));
        cout<<may<<'\n';
    }
    return 0;
}
