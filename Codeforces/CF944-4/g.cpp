#include <bits/stdc++.h>
using namespace std;

#define uf(i, a, b) for (int i = (a); i < (b); i++)
#define df(i, a, b) for (int i = (a); i >= (b); i--)
#define cln(v) cout << v << '\n'
#define ce(v) cout << v << ' '
#define ln cout << '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		map<int, priority_queue<int>> mapa;
		vector<int> num(n);
		uf(i, 0, n)
		{
			cin >> num[i];
			mapa[num[i] >> 2].push(-num[i]);
		}
		uf(i, 0, n)
		{
			ce(mapa[num[i] >> 2].top() * -1);
			mapa[num[i] >> 2].pop();
		}
		ln;
	}
	return 0;
}
