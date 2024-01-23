#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1921/problem/D

#define uf(i, a, b) for(int i=(a); i<(b); i++)
#define df(i, a, b) for(int i=(a); i>=(b); i--)
#define cln(v) cout<<v<<'\n';
#define ce(v) cout<<v<<' ';
#define ln cout<<'\n';
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, n, m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> num(n);
        vector<int> mum(m);
        for (int i = 0; i <n; i++)
        {
            cin>>num[i];
            /* code */
        }
        for (int i = 0; i <m; i++)
        {
            cin>>mum[i];
            /* code */
        }
        sort(num.begin(), num.end());
        sort(mum.begin(), mum.end());
        ull suma=0;
        int num1=0, num2=n-1;
        int mum1=m-1, mum2=0;
        int a, b;
        while(num1<=num2){
            a=abs(num[num1]-mum[mum1]);
            b=abs(num[num2]-mum[mum2]);
            if(a>b) suma+=a, num1++, mum1--;
            else suma+=b, num2--, mum2++;
        }
        cout<<suma<<"\n";
    }
    return 0;
}
