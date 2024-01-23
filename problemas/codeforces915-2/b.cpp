#include <iostream> 
using namespace std;

// Problema B: https://codeforces.com/contest/1905/problem/B

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, n;
    cin>>t;
    int a, b, cont;
    while(t--){
        cin>>n;
        cont=0;
        int cant[n]={};
        n--;
        while(n--){
            cin>>a>>b;
            cant[--a]++;
            cant[--b]++;
        }
        for(int num: cant) if(num==1) cont++;
        cout<<(cont+1)/2<<'\n'; 
    }
    return 0;
}
