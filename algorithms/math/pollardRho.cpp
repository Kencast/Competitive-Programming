#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

//  Pollard Rho to factorize a number o(n) and <O(square(n))

ll mulmod (ll a, ll b, ll c) { 
    ll x = 0, y = a%c;
    while (b > 0){
        if (b % 2 == 1) x = (x+y) % c;
        y = (y*2) % c;
        b /= 2;
    }
    return x % c;
}

ll expLogMod(ll base, ll exp, ll mod){//O(log b)
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

bool rabin(ll n){
    if(n==2) return true;
    if(n == 1 || n%2==0) return false;
    const int ar[] = {2,3,5,7,11,13,17,19,23};
    for(int j=0; j<9; j++) 
        if(!esPrimoProb(n,ar[j])) return false;
    return true;
}

random_device rd;
mt19937 generator(rd());
uniform_int_distribution<int> ran(1, 20);

ll GCD(ll a, ll b){return a?GCD(b %a, a):b;}


ll rho(ll n){
    if(n%2==0) return 2;
    ll x=2, y=2, mcd=1; 
    ll c=ran(generator); //elige una constance para x^2+c
    while(mcd==1){ //si el mcd es 1 se sigue probando
        x=(mulmod(x, x, n)+c)%n;
        y=(mulmod(y, y, n)+c)%n;
        y=(mulmod(y, y, n)+c)%n;
        if(x>y)mcd=GCD(x-y, n);
        else mcd=GCD(y-x, n);
    }
    return (mcd==n)? rho(n): mcd; //if mcd equals n then try again
}

void fact(ll n){ 
    stack<ll> pila;
    list<ll> lista;
    pila.push(n);
    ll num, factA;
    while(!pila.empty()){
        num=pila.top(); pila.pop();
        if(rabin(num)) lista.push_back(num);
        else if(num!=1){
            factA=rho(num);
            pila.push(factA); 
            pila.push(num/factA);
        }
    }
    lista.sort(); //to print it in order
    list<ll>::iterator it=lista.begin();
    int i=lista.size()-1;
    while(i--){
        cout<<*it<<'x';
        it++;
    }
    cout<<*it<<'\n';
}

