#include <bits/stdc++.h>
using namespace std;

// Problema A: https://codeforces.com/contest/1920/problem/A

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, n, cont;
    int tipo, x, inf, sup;
    cin>>t;
    while(t--){
        cin>>n;
        inf=0, sup=INT32_MAX;
        list<int> num;
        while(n--){
            cin>>tipo>>x;
            if(tipo==1) inf=max(inf, x);
            else if(tipo==2) sup=min(sup, x);
            else num.push_back(x);
        }
        if(inf>sup){
            cout<<"0\n";
            continue;
        }
        cont=sup-inf+1;
        for(int c: num){
            if(c>=inf && c<=sup) cont--;
        }
        cout<<cont<<'\n';
    }
    return 0;
}
