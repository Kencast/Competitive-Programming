#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef tuple<int, int, int> tp;
list<tp> lista;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;

public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }
  int findSet(int i) { 
    return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

  bool isSameSet(int i, int j) { 
    return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }

    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

void meter(int t, int i, int j){
    lista.push_back({t, i, j}); //(peso, i, j)
}

int kruskal(int n){
    lista.sort();
    int cost=0, aristas=0;
    tp aux;
    UnionFind uf(n);
    while(!lista.empty()){
        aux=lista.front(), lista.pop_front();
        if(!uf.isSameSet(get<1>(aux), get<2>(aux))){
            cost+=get<0>(aux), aristas++;
            uf.unionSet(get<1>(aux), get<2>(aux));
            if(aristas==n-1) return cost;
        }
    }
    return cost;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, c, i, j, t;
    cin>>a>>c;
    while(c--){ //i,j >=1
        cin>>i>>j>>t; //t=peso
        meter(t, i-1, j-1);
    }
    cout<<kruskal(a)<<'\n';
    return 0;
}