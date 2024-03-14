#include <bits/stdc++.h>
using namespace std;

#define uf(i, a, b) for(int i=(a); i<(b); i++)
#define df(i, a, b) for(int i=(a); i>=(b); i--)
#define cln(v) cout<<v<<'\n'
#define ce(v) cout<<v<<' '
#define ln cout<<'\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pr;

string s;

int solve(){
    int in=s.size()-1;
    int start=in, cont=0;
    for(int i=in; i>=0; i--){
        if(s[i]=='2') cont+=start-i, start--;
    }
    int pos=start;
    for(int i=in; i>=0; i--){
        if(s[i]=='1') cont+=start-pos, start--;
        if(s[i]!='2') pos--;
    }
    return cont;
}

int bubbleSort(int n)
{
    int i, j;
    int cont=0;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                swap(s[j], s[j + 1]);
                cont++;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    return cont;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>s;
    cln(solve());
    cln(bubbleSort(s.size()));
    return 0;
}