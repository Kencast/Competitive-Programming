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
    int a, k, n;
    cin >> n >> a >> k;
    int i = 1;
    while (a * i < n)
    {
        if ((n - a * i) % k == 0)
        {
            cln(1);
            return 0;
        }
        i++;
    }
    cln(0);
    return 0;
}