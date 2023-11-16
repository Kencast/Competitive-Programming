#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, num, i;
    map<int, int> freq;
    char resp='N';
    cin>>n;
    n*=3;
    while(n--){
        cin>>num;
        freq[num]+=1;
    }
    map<int, int>::iterator k=freq.begin();
    while(k!=freq.end()){
        if((k->second%3)!=0){
            resp='Y';
        }
        ++k;
    }
    cout<<resp<<'\n';
    return 0;
}
