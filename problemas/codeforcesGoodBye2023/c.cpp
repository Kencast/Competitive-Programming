#include <iostream>
using namespace std;
typedef long long int ll;

// https://codeforces.com/contest/1916/problem/C

int fun(int x){
    return ((x+1)/3)*2;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, n;
    ll num, suma, cont;
    cin>>t;
    while(t--){
        cin>>n;
        suma=cont=0;
        cin>>num;
        suma+=num;
        cont+=num%2;
        if(n>1) cout<<num<<' ';
        for (int i = 2; i<n; i++)
        {
            cin>>num;
            suma+=num, cont+=num%2;
            (cont%2)? cout<<suma-fun((cont+3)/2)+1<<' ': cout<<suma-fun(cont/2)<<' ';
        }
        if(n==1) cout<<suma<<'\n';
        else {
            cin>>num; suma+=num, cont+=num&1;
            (cont%2)? cout<<suma-fun((cont+3)/2)+1<<'\n': cout<<suma-fun(cont/2)<<'\n';
        }
    }
    return 0;
}
