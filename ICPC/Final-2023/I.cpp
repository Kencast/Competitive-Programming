#include <bits/stdc++.h>
using namespace std;
#define num 1000000007
typedef unsigned long long int ul;

ul gauss(ul n){
    return ((n*(n+1))%num*500000004)%num;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i, j;
    string word;
    int letras[26]={};
    cin>>word;
    ul res=0, n;
    cin>>n;
    n%=num;
    for(j=word.size()-1; j>=0; j--){
        letras[word[j]-'a']++;
        for(i=0; i<(word[j]-'a'); i++){
            res=(res+letras[i]*gauss(n))%num;
        }
    }
    for(i=0; i<26; i++) letras[i]=0;
    n--;
    for(j=0; j<word.size(); j++){
        letras[word[j]-'a']++;
        for(i=0; i<(word[j]-'a'); i++){
            res=(res+letras[i]*gauss(n))%num;
        }
    }
    cout << res << '\n';
    return 0;
}
