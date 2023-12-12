#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

bool numeros[10000000];

void primos(){
    int n=10000000;
    int num=2, i;
    for(i = 0; i <n; i++)
    {
        numeros[i]=true;
    }
    numeros[0]=numeros[1]=false;
    while(num*num<n){
        i=2;
        while(num*i<n){
            numeros[num*i]=false;
            i++;
        }
        num++;
        while(!numeros[num]) num++;
    }
}