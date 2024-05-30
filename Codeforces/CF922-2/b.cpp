#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1918/problem/B

#define uf(i, a, b) for(int i=(a); i<(b); i++)
#define df(i, a, b) for(int i=(a); i>=(b); i--)
#define cln(v) cout<<v<<'\n'
#define ce(v) cout<<v<<' '
#define ln cout<<'\n'
typedef long long ll;
typedef unsigned long long ull;

class ob{
public:
    int a, b;

    bool operator<(const ob &c) const{
        return a+b<c.a+c.b;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ob> num(n);
        for(int i=0; i<n; i++) cin>>num[i].a;
        for(int i=0; i<n; i++){
            cin>>num[i].b;
        }
        sort(num.begin(), num.end());
        uf(i, 0, n-1){
            ce(num[i].a);
        }
        cln(num[n-1].a);
        uf(i, 0, n-1){
            ce(num[i].b);
        }
        cln(num[n-1].b);
    } 
    return 0;
}