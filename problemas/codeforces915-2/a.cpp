#include <iostream>
using namespace std;

// Problema A
//https://codeforces.com/contest/1905/problem/A

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    int a, b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<max(a, b)<<'\n';
    }
    return 0;
}
