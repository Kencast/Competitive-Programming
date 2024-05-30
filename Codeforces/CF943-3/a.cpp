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
    int n, t, y;
    cin >> t;
    while (t--)
    {
        cin >> n;
        y = n - 1;
        int res = 0;
        int p, aux;
        while (y)
        {
            aux = gcd(y, n);
            if (y + aux > res)
                res = y + aux, p = y;
            y--;
        }
        cln(p);
    }
    return 0;
}