#include <vector>
#include <bitset>
using namespace std;

#define vector<vector<int>> vvi

//n=cantidad de nodos
bitset<(1<<n)+5> vis;
bool memo[(1<<n)+2]={};

int countBit(int num){
	int cont=0;
	while(num){//verifica si el ultimo bit está prendido y divide num;
		cont+=num&1; 
		num>>=2;
	}
	return cont;
}

bool test(int num, int i){
	return num&(1<<i); //true si el bit i está prendido
}

int clear(int num, int i){
	return num&~(1<<i); //apaga el bit i
}

bool esClique(int msk, vvi G){
	if(vis[msk]) return memo[msk];//si ya se calculó
	if(msk==(msk&(-msk))) return true; //solo tiene un nodo, true
	int i, j;
	for(i=0; !test(msk, i); i++); //encuentra el primer bit prendido
	for(j=i+1; !test(msk, j); j++); //encuentra el segundo bit prendido
	vis[msk]=true;
	return memo[msk]=G[i][j] && esClique(clear(msk, i), G) //si (i, j) está conectado
	&& esClique(clear(msk, j), G);// y si el grafo resultante es un clique;
}

int cliqueMax(vvi G){
	int msk=0;
	for(int i=0; i<(1<<G.size()); i++){ //1<<G.size()=2^n
		if(esClique(i, G) && countBit(i)>coutBit(msk)){
			msk=i;
		}
	}
	//prueba todas las posibles combianciones de nodo y verifica si un clique
	//guardando el máximo
	return msk;
}