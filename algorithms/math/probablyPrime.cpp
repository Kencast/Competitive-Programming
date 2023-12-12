#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//  The Miller-Rabin algorithm O(k*log(n)^2) aproximadamente

ll mulmod (ll a, ll b, ll c) { //mul (a*b)%c in log(b) to avoid overflow
    ll x = 0, y = a%c;
    while (b > 0){
        if (b % 2 == 1) x = (x+y) % c;
        y = (y*2) % c;
        b /= 2;
    }
    return x % c;
}

ll expLogMod(ll base, ll exp, ll mod){//O(log exp)
    if(!exp) return 1;
    ll r= expLogMod(base,exp/2,mod); 
    r=mulmod(r,r,mod);
    if(exp%2) r=mulmod(base,r,mod);
    return r;
}

bool esPrimoProb(ll num, int a)
{
    if(num == a) return true;
    ll exp = num-1;
    ll cantFactores=0;
    //se descompone (a^exp-1) en factores hasta exp sea impar
    //si num divide a alguno de esos factores entonces num es primo
    
    while(exp%2==0) cantFactores++, exp/=2;
    ll x=expLogMod(a, exp, num); //a^exp donde exp es impar
    if(x==1 || x+1==num) return true; //evalua (x-1)%num y (x+1)%num

    while(--cantFactores){ //cantFactores-1 veces
        x=mulmod(x, x, num);
        if(x==1) return false; //si x=1 entonces x*x=1
        if(x+1==num) return true; //si (x+1)%num
    }
    return false;
}

bool rabin(ll n){ //perform 9 iterations to increase probability
    //probability of succes 1/4^j
    if(n==2) return true;
    if(n == 1 || n%2==0) return false;
    const int ar[] = {2,3,5,7,11,13,17,19,23};
    for(int j=0; j<9; j++) 
        if(!esPrimoProb(n,ar[j])) return false;
    return true;
}