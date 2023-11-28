#include <bits/stdc++.h>
using namespace std;

int buscar(string p, vector<string> word){
    int inf=0, sup=word.size();
    int m=(inf+sup)/2;
    while(inf+1<sup){
        if(word[m]>p) sup=m;
        else inf=m;
        m=(inf+sup)/2;
    }
    return inf;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin>>n>>q;
    vector<string> pal(n);
    for (int i = 0; i < n; i++)
    {
        cin>>pal[i];
    }
    sort(pal.begin(), pal.end());
    string a, b;
    int p, k;
    while(q--){
        cin>>a>>b;
        p=buscar(a, pal);
        k=buscar(b, pal);
        if(pal[p]==a || !p) cout<<k-p+1<<'\n';
        else cout<<k-p<<'\n';
    }
    return 0;
}
