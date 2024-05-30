#include <bits/stdc++.h>
using namespace std;
typedef list<int>::iterator it;
int hojas[200005];

//https://codeforces.com/contest/1919/problem/D

bool bueno(it i){
    it prev=i, nxt=i;
    prev--, nxt++;
    return hojas[*i]-1==hojas[*prev] || hojas[*i]-1==hojas[*nxt];
}

class obj{
public:
    it punt;

    obj(it a){
        punt=a;
    }

    bool operator<(const obj &a) const{
        return hojas[*punt]<hojas[*a.punt];
    }
};


int main(int argc, char const *argv[])
{
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int cont=1, num, menor=n; 
        list<int> lista;
        lista.push_back(0);
        priority_queue<obj> cola;
        for(int i=1; i<=n; i++){
            cin>>hojas[i];
            menor=min(menor, hojas[i]);
            lista.push_back(i);
        }
        lista.push_back(0);
        it st=lista.begin(); st++;
        hojas[0]=-2;
        bool esta[n+2]={};
        for(int i=1; i<=n; i++){
            if(bueno(st)) cola.push(obj(st)), esta[i]=true;
            st++;
        }
        while(!cola.empty()){
            obj nod=cola.top(); cola.pop();
            it prev=nod.punt, nxt=nod.punt;
            prev--, nxt++;
            lista.erase(nod.punt);
            if(!esta[*prev] && bueno(prev)){
                esta[*prev]=true;
                cola.push(obj(prev));
            }
            if(!esta[*nxt] && bueno(nxt)){
               esta[*nxt]=true;
               cola.push(obj(nxt));
            }
        }
        st=lista.begin(); st++;
        if(!menor && (lista.size()==3 || bueno(st))){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}

