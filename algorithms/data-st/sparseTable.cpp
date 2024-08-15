#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vll;
typedef long long ll;

// Sparse table for associative operations
// O(nlongn) for building and O(longn) for query

// pre C++20
int log2_floor(unsigned long long i)
{
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int n = 10;
int lg = log2_floor(n);
vector<vll> st(lg+1, vll(n));

ll f(ll a, ll b){
	return a+b;
}

void build()
{
    for (int i = 1; i <= lg; i++){
	    for(int j=0; j+(1<<i)<=n; j++)
		    st[i][j]=f(st[i-1][j], st[i-1][j+(1<<(i-1))]);

    }

}

ll query(int l, int r){ // [l, r]

	ll sum=0;
	for(int i=lg; i>=0; i--){
		if((1<<i)<=r-l+1){
			sum+=st[i][l];
			l+=(1<<i);
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	for(int i=0; i<10; i++) st[0][i]=i+1;
	build();
	cout<<query(0, 5)<<'\n';
	return 0;
}
