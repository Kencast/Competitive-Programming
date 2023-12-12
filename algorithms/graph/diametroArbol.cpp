#include <iostream>
#include <queue> 
using namespace std;

class Nodo{
public:
    int valor;
    Nodo* next;
    
    Nodo(int dat){
        valor=dat;
        next=nullptr;
    }
};

class Lista{ //lista enlazada simple
public:
    Nodo* head;
    Nodo* last;
    int len;

    Lista(){
        head=nullptr;
        len=0;
    }

    void append(int& dat){
        if(!len) head=last=new Nodo(dat);
        else{
            last->next=new Nodo(dat);
            last=last->next;
        }
        len++;
    }

    ~Lista(){
        Nodo* aux;
        while(head){
            aux=head;
            head=head->next;
            delete aux;
        }
    }
};

int lastNode; //guarda al nodo más alejado

void recorrer(Lista vec[], int vis[], int k){ //bfs desde un nodo cualquiera
    queue<int> cola;
    Nodo* aux;
    int hijo;
    cola.push(k);
    while(!cola.empty()){
        lastNode=cola.front();
        cola.pop();
        aux=vec[lastNode].head;
        while(aux){
            hijo=aux->valor;
            if(hijo!=k && !vis[hijo]){
                vis[hijo]=vis[lastNode]+1;
                cola.push(hijo);
            }
            aux=aux->next;
        }
    }
}

void recorrerUp(Lista vec[], int alt[], int vis2[], int k){ //bfs desde el nodo más alejado
    queue<int> cola;
    Nodo* aux;
    int hijo;
    cola.push(k);
    vis2[k]=1;
    while(!cola.empty()){
        lastNode=cola.front();
        cola.pop();
        aux=vec[lastNode].head;
        while(aux){
            hijo=aux->valor;
            if(!vis2[hijo] && (alt[lastNode]==alt[hijo]+1 || alt[lastNode]==alt[hijo]-1)){
                vis2[hijo]=vis2[lastNode]+1;
                cola.push(hijo);
            }
            aux=aux->next;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, c, i, j;
    cin>>n>>c;
    Lista vecinos[n];
    int visitados[n]={}; //sirve como visitados y guarda la altura del nodo
    while(c--){
        cin>>i>>j;
        vecinos[i].append(j);
        vecinos[j].append(i);
    }
    recorrer(vecinos, visitados, 0); //guarda en lastNode el primer nodo más alejado
    int visita2[n]={};
    recorrerUp(vecinos, visitados, visita2, lastNode);
    cout<<visita2[lastNode]-1<<'\n'; //altura del segundo nodo más alejado
    return 0;
}