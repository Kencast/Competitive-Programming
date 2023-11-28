#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    long meses[n+1];
    meses[0]=0;
    for (int i = 1; i <=n; i++)
    {
        cin>>meses[i];
        meses[i]+=meses[i-1];
    }
    int d1, m1, y1;
    int d2, m2, y2;
    cin>>d1>>m1>>y1;
    cin>>d2>>m2>>y2;
    ull res=meses[n]*(y2-y1);
    long long aux=0;
    if(m1<=m2){
        aux+=meses[m2-1]-meses[m1-1];
        (d1>=d2)? aux-=d1-d2: aux+=d2-d1;
        res+=aux;
    }
    else{
        aux+=meses[m1-1]-meses[m2-1];
        (d1>=d2)? aux-=d1-d2: aux+=d2-d1;
        res-=aux;
    }
    cout<<res<<'\n';
    return 0;
}
