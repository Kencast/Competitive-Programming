#include <bits/stdc++.h>
using namespace std;

int cont;
int p=1000000007, q=313;



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, key=0;
    cin>>n>>k;
    int num[n+1];
    int msk[k+1];
    int elv[k+1];
    long int aux=0;
    unordered_map<int, int> ind;
    cont=k;
    elv[0]=1;
    for (int i = 1; i <=k; i++)
    {
        aux=(elv[i-1]*q)%p;
        elv[i]=aux;
        msk[i]=0;
    }
    for (int i = 1; i <=n; i++)
    {
        cin>>num[i];
        if(!msk[num[i]]) cont--;
        msk[num[i]]++;
        if(!cont){
            aux=0;
            for(int j=1; j<=k; j++){
                msk[j]--;
                if(!msk[j]) cont++;
                aux+=elv[j]*msk[j], aux%=p;
	        }
            key=aux;
        }
        else{
            //aux=(key+elv[num[i]])%p, key=aux;
            aux=0;
            for(int j=1; j<=k; j++){
                aux+=elv[j]*msk[j], aux%=p;
	        }
            key=aux;
        }
        num[i]=key;
        if(ind.find(key)==ind.end()) ind[key]=i;
    }
    key=0;
    for (int i = 1; i <=n; i++)
    {
        key=max(key, i-ind[num[i]]);
    }
    cout<<key<<'\n';
    return 0;
}
