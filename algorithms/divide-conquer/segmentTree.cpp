#include <bits/stdc++.h>
using namespace std;

#define uf(i, a, b) for(int i=(a); i<(b); i++)
#define df(i, a, b) for(int i=(a); i>=(b); i--)
#define cln(v) cout<<v<<'\n'
#define ce(v) cout<<v<<' '
#define ln cout<<'\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pr;

const int N = 400001;  
ll arbol[N]; // N>=2*len
int len; // array size 

ll operation(ll a, ll b){
    //example
    return min(a, b);
}

void construir(){
    int p;
    for(int i=len-1; i>0; i--){
        p=i<<1;
        arbol[i]=operation(arbol[p], arbol[p+1]);
    }
}

ll query(int i, int j){
    i+=len;
    j+=len;
    ll res=INT64_MAX;
    while(i<j){
        if(i&1){
            res=operation(res, arbol[i]);
            i++;
        }
        if(j&1){
            j--;
            res=operation(res, arbol[j]);
        }
        i>>=1; j>>=1;
    }
    return res;
}
  

void update(int i, ll num){
    int p;
    i+=len;
    arbol[i]+=num;
    while(i>1){
        i>>=1;
        p=i<<1;
        arbol[i]=operation(arbol[p], arbol[p+1]);
    }
}

int main(int argc, char const *argv[])
{
    cin>>len; //size
    for(int i=0; i<len; i++){
        cin>>arbol[len+i];
    }
    construir();
    return 0;
}
