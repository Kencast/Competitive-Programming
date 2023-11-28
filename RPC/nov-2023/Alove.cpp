#include <bits/stdc++.h>
using namespace std;

string mayor(string a, string b){
    int n=min(a.size(), b.size()), i=0;
    if(a.size()>n){
        while(i<a.size()){
            if(a[i]>b[i%n]) return a;
            if(a[i]<b[i%n]) return b;
            i++;
        }
    }
    else{
        while(i<b.size()){
            if(b[i]>a[i%n]) return b;
            if(b[i]<a[i%n]) return a;
            i++;
        }
    }
    return a;
}

string menor(string a, string b){
    int n=min(a.size(), b.size()), i=0;
    if(a.size()>n){
        while(i<a.size()){
            if(a[i]>b[i%n]) return b;
            if(a[i]<b[i%n]) return a;
            i++;
        }
    }
    else{
        while(i<b.size()){
            if(b[i]>a[i%n]) return a;
            if(b[i]<a[i%n]) return b;
            i++;
        }
    }
    return a;
}

int main(int argc, char const *argv[])
{
    string a, b, c;
    cin>>a>>b>>c;
    string may=mayor(a, mayor(b, c));
    string men=menor(a, menor(b, c));
    string medio="";
    if(a!=may && a!=men) medio=a;
    else if(b!=may && b!=men) medio=b;
    else if(medio=="") medio=c;
    cout<<may+medio+men+'\n';
    return 0;
}
