#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int num[2]={};
        for(char a: s) num[a-'A']++;
        if(num[0]>num[1]) cout<<"A\n";
        else cout<<"B\n";
    }
    return 0;
}
