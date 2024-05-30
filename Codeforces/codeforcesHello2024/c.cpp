#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1919/problem/C

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, cont1, n, res;
    int men, may;
    cin>>t;
    while(t--){
        cont1=0;
        cin>>n;
        list<int> a;
        list<int> b;
        a.push_back(INT32_MAX);
        b.push_back(INT32_MAX);
        for(int i=0; i<n; i++){
            cin>>res;
            men=min(a.back(), b.back());
            may=max(a.back(), b.back());
            if(res<=men){
                (a.back()==men)? a.push_back(res):b.push_back(res);
                continue;
            }
            if(res<=may) (a.back()==may)? a.push_back(res):b.push_back(res);
            else{
                (a.back()==men)? a.push_back(res): b.push_back(res);
                cont1++;
            }
        }
        cout<<cont1<<'\n';
    }
    return 0;
}
