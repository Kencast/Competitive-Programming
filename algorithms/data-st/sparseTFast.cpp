#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vll;
typedef long long ll;

// Sparse table for idempotent functions like minimum/maximum, gcd, etc
// O(nlogn) for building and O(1) for query

// pre C++20
int log2_floor(unsigned long long i)
{
	return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int n = 10;
int lg = log2_floor(n);
vector<vll> st(lg + 1, vll(n));

ll f(ll a, ll b)
{
	return min(a, b);
}

void build()
{
	for (int i = 1; i <= lg; i++)
	{
		for (int j = 0; j + (1 << i) <= n; j++)
			st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	}
}

ll query(int l, int r)
{ // [l, r]
	int i = log2_floor(r - l + 1);
	return min(st[i][l], st[i][r - (1 << i) + 1]);
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 10; i++)
		st[0][i] = i + 1;
	build();
	cout << query(3, 8) << '\n';
	return 0;
}
