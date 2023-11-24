#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;


int otra(int n, int k){
    int mn=n;
    int num[n+1];
    int msk[k+1]={};
    for (int i = 1; i <=n; i++) //leer el input y guardar las frecuencias
    {
        cin>>num[i];
        msk[num[i]]++;
    }
    
    for (int i = 1; i <=k; i++)
    { //sacar la minima frecuencia
        mn=min(mn, msk[i]);
        msk[i]=0;
    }
    if(!mn) return 0;
    int len=k*mn, cont=0; //len es tamaño de la ventana
    for (int i = 1; i <=len; i++)
    { //calcular las frecuencias en la ventana
        msk[num[i]]++;
    }
    for (int i = 1; i <=k; i++)
    { //contar las frecuencias iguales a la mínima 
        if(msk[i]==mn) cont++;
    }
    int i=1, j=len;
    while(j<n){ //deslizar la ventana una posición
        if(cont==k) return len;
        if(msk[num[i]]==mn) cont--;
        msk[num[i]]--;
        if(msk[num[i]]==mn) cont++;
        i++, j++;
        if(msk[num[j]]==mn) cont--;
        msk[num[j]]++;
        if(msk[num[j]]==mn) cont++;
    }
    return (cont==k)? len:0;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, key=0, cont;
    int q=13901;
    cin>>n>>k;
    if(k>600){ //solución 2, usando sliding window
        cout<<otra(n, k)<<'\n';
        return 0;
    }
    int num[n+1];
    int msk[k+1]={};
    ull aux;
    ull p=(1ull<<62)-1;
    ull exp;
    unordered_map<ull, int> ind;
    ind[0]=0;
    cont=k; //cant de frecuencias en cero
    for (int i = 1; i <=n; i++)
    {
        cin>>num[i];
        if(!msk[num[i]]) cont--; 
        msk[num[i]]++;
        if(!cont){ //si ya se completó un bloque sacar hash y resetearlo
            aux=0, exp=1;
            for(int j=1; j<=k; j++){
                msk[j]--;
                if(!msk[j]) cont++;
                aux+=exp*msk[j], aux%=p;
                exp=(exp*q)%p;
	        }
        }
        else{ //sacar solo el hash
            //aux=(key+elv[num[i]])%p, key=aux;
            aux=0, exp=1;
            for(int j=1; j<=k; j++){
                aux+=exp*msk[j], aux%=p;
                exp=(exp*q)%p;
	        }
        }
        if(ind.find(aux)==ind.end()) ind[aux]=i;
        else key=max(key, i-ind[aux]);
    }
    cout<<key<<'\n';
    return 0;
}
