#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void imprimir(vi R){
    for(int i = 0; i < R.size(); i++){
        cout << R[i] << ' ';
    }
    cout << "\n";
}

vvi setMulti(vvi A, vvi B){
    vvi R;
    for(int i = 0, m = 0; i < A.size(); i++){
        vi T;
        for(int j = 0; j < A[i].size(); j++)
            T.push_back(A[i][j]);
        for(int k = 0; k < B.size(); k++){
            R.push_back(T);
            for(int n = 0; n < B[k].size(); n++)
                R[m].push_back(B[k][n]);
                m++;
        }
    }                 
    return R;
}

vvi generarMat(vi C){
    vvi R;
    for(int i = 0; i < C.size(); i++){
        vi T; T.push_back(C[i]);
        R.push_back(T);
    }
    return R;
}

vvi setExpoLog(vi C, int n){
    vvi R;
    if(!n) return R;
    if(n == 1) return generarMat(C);
    R = setExpoLog(C,n/2);
    R = setMulti(R,R);
    if(n%2) R = setMulti(generarMat(C),R);
    return R;
}

int count(vi A){
    int n = 0;
    for(int i = 0; i < A.size(); i++) n += A[i];
    return n;
}

int main(){
    vi A = {0,1};   //Conjunto de numeros
    vvi R = setExpoLog(A,5); // el tamano de las listas finales
    for(int i = 0; i < R.size(); i++)
        if(count(R[i]) == 3) imprimir(R[i]);    // Todas las posibilidades con solo 3 1's
    return 0;
}
