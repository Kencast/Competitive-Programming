#include <iostream>
using namespace std;
typedef long long int ll;

// https://codeforces.com/contest/1916/problem/B

ll gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t, a, b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(b%a==0) cout<<b*(b/a)<<'\n';
        else cout<<(b*a)/gcd(b, a)<<'\n';
    }
    return 0;
}
