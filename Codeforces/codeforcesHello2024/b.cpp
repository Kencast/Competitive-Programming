#include <iostream>
using namespace std;
 
// https://codeforces.com/contest/1919/problem/B
 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, cont1, cont2, n;
    cin>>t;
    while(t--){
        string a;
        cont1=cont2=0;
        cin>>n;
        cin>>a;
        for(char b: a){
            (b=='+')? cont1++: cont2++;
        }
        cout<<abs(cont1-cont2)<<'\n';
    }
    return 0;
}
