#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull fun(long i){
    return (i*(i+1))/2;
}

int main(int argc, char const *argv[])
{
    long i=2, cont=0;
    ull n;
    cin>>n;
    while(n>=3){
        if(fun(i)>n) i=2;
        n-=fun(i);
        cont++, i++;
    }
    cout<<cont<<' '<<n<<'\n';
    return 0;
}
