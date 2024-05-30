#include <iostream>

using namespace std;
typedef long long int li;

// https://codeforces.com/contest/1916/problem/A

void solve(int num, int k){
    cout<<2023/num;
    while(k--) cout<<" 1";
    cout<<'\n';
}

int main(int argc, char const *argv[])
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int t, n, k;
    li num, a;
    li year=2023;
    cin>>t;
    while(t--){
        cin>>n>>k;
        num=1;
        while(n--) cin>>a, num*=a;
        if(num>year || year%num) cout<<"NO\n";
        else{
            cout<<"YES\n";
            if(k==1) cout<<year/num<<'\n';
            else solve(num, k-1);
        }   
    }

    return 0;
}
