#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll eulerTotient(ll n){
    ll res=n;
    ll r=2;
    while(r*r<=n){
        if(n%r==0) res/=r, res*=r-1;
        while(n%r==0) n/=r;
        r+=1+(r!=2);
    }
    return (n>1)? res-=res/n:res;
}