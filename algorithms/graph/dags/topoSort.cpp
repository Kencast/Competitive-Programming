#include <bits/stdc++.h>
using namespace std;

const int tam=500;
vector<list<int>> adj(tam);
int ind[tam]; //indegree
int n; 

void toposort(){
	queue<int> cola;
	list<int> resp;
	for(int i=0; i<n; i++){
		if(!ind[i]) cola.push(i);
	}
	while(!cola.empty()){
		int vect=cola.front();
		cola.pop();
		resp.push_back(vect);
		for(int nr: adj[vect]){
			ind[nr]--;
			if(!ind[nr]) cola.push(nr);
		}
	}
	// if(resp.size()<n) then there is a cycle
	// else return resp
}

int main(){

	return 0;
}

