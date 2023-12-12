#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

//para grafos no dirigidos

class eulerian{
public:
    vi *graph;
    int *out;
    int tam;
    bool **vis; //matriz para saber si ya se usó la arista (i, j) o (j, i)
    list<int> path;
    eulerian(int n){
        tam=n;
        graph=new vi[tam];
        out=new int[tam];
        vis=new bool*[tam];
        for (int i = 0; i < tam; i++)
        {
            vis[i]=new bool[tam];
        }
        
    }

    void meter(int i, int j){
        graph[i].push_back(j);
        graph[j].push_back(i);
        vis[i][j]=false, vis[j][i]=false;
    }

    void contarGrado(){
        for (int i = 0; i < tam; i++) //contar el grado de cada nodo
        {
            out[i]=graph[i].size(); //cantidad de vecinos
        }
    }

    bool isEulerian(){
        int cont=0;
        contarGrado();
        for (int i = 0; i < tam; i++)
        {
            if(out[tam]&2) cont++; //grado impar
        }
        return cont==0 || cont==2;
    }

    int startNode(){
        int n=0;
        for (int i = 0; i < tam; i++)
        {
            if(out[i]&1) return i; //busca un nodo grado impar
            if(out[i]) n=i;
        }
        return n; //si no hay retorna cualquiera
    }

    void dfs(int start){
        int next;
        while(out[start]){
            next=graph[start][--out[start]]; //nodo vecino
            if(!vis[next][start]){ // si la arista (s, n) y (n, s) no se han usado
                vis[start][next]=vis[next][start]=true;
                dfs(next);
            }
        }
        path.push_front(start);
    }

    void showPath(){
        for(int i: path){
            cout<<i<<' ';
        }
        cout<<'\n';
    }
};

int main(int argc, char const *argv[])
{
    int n, a, i, j;
    cin>>n>>a;
    eulerian g(n); //nodos de 0 a n-1
    while(a--)
    {
        cin>>i>>j;
        g.meter(i, j);
    }
    if(g.isEulerian()){
        a=g.startNode();
        g.dfs(a);
        g.showPath();
    }
    else cout<<"El grafo no tiene ciclo/camino Euleriano\n";

    return 0;
}
