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
        int x, y;
        cin >> x >> y;
        int cont = 0;
        if (y & 1)
            cont = y / 2 + 1, x -= (y / 2) * 7 + 11;
        else
            cont = y / 2, x -= cont * 7;
        if (x > 0)
            cont += (x % 15) ? x / 15 + 1 : x / 15;
        cln(cont);
    }
    return 0;
}