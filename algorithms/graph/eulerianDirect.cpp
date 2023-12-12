#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

//Para grafos dirigidos

class eulerian{
public:
    vi *graph;
    int *in;
    int *out;
    int tam;
    list<int> path; //guardar el camino
    eulerian(int n){
        tam=n;
        graph=new vi[tam];
        in=new int[tam];
        out=new int[tam];
    }

    void meter(int i, int j){
        graph[i].push_back(j);
    }

    void contarGrado(){
        for (int i = 0; i < tam; i++)
        {
            in[i]=out[i]=0;
        }
        for (int i = 0; i < tam; i++) //contar el grado de cada nodo
        {
            for(int hij=0; hij<graph[i].size(); hij++){
                out[i]++, in[graph[i][hij]]++;
            }
        }
    }

    bool isEulerian(){
        int startN=0, endN=0;
        contarGrado();
        for (int i = 0; i < tam; i++)
        { //la diferencia entre in[i] y out[i] debe ser 0 o 1
            if(abs(in[i]-out[i])>1) return false; 
            if(out[i]-in[i]==1) startN++; //tiene un nodo adyacente extra
            else if(in[i]-out[i]==1) endN++; //tiene un nodo incidente extra
        }
        return startN==endN && startN<2;
        //si todos start=endN y startN=0 es un ciclo, si startN=1 es un camino
    }

    int startNode(){ //busca el nodo de inicio tal que out[i]>in[i]
        int n=0;
        for (int i = 0; i < tam; i++)
        {
            if(out[i]-in[i]==1) return i;
            if(out[i]) n=i;
        }
        return n;
    }

    void dfs(int start){
        int next;
        while(out[start]){
            next=graph[start][--out[start]]; //vecino de start
            dfs(next);
        }
        path.push_front(start); //ya se exploraron sus aristas
    }

    void showPath(){
        for(int i: path){ //para imprimir
            cout<<i<<' ';
        }
        cout<<'\n';
    }
};

int main(int argc, char const *argv[])
{
    int n, a, i, j;
    cin>>n>>a; // cantidad de nodos y aristas, respectivamente
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
