#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, j=0;
    cin>>n; 
    int mat[n][n];
    int extra[n+1];
    for(int i=0; i<n; i++){
        j=0;
        for(int p=0; p<n; p++) mat[i][p]=j, j++;
    }
    for(int i=0; i<=n; i++) extra[i]=j, j++;
    for(int res=1; res<n; res++){
        for(int i=0; i<n; i++){
            string s=""; j=i;
            for(int p=0; p<n; p++) s+=to_string(mat[p][j])+" ", j=(j+res)%n;
            s+=to_string(extra[res-1]);
            cout<<s+"\n";
        }
    }
    return 0;
}
