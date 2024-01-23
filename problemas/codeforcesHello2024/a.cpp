#include <iostream>
using namespace std;

// https://codeforces.com/contest/1919/problem/A

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, a, b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if((a+b)&1) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
    return 0;
}
