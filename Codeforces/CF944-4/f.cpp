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
        ll r;
        cin >> r;
        ll r2 = (r + 1) * (r + 1);
        ll x, x2;
        ll cont = 0;
        ll inf, sup, m;
        for (x = 0; x <= r; x++)
        {
            x2 = x * x;
            inf = 0, sup = r + 1;
            while (inf + 1 < sup)
            {
                m = (inf + sup) / 2;
                (x2 + m * m >= r2) ? sup = m : inf = m;
            }
            while (x2 + inf * inf >= r * r && inf >= 0)
                cont++, inf--;
        }
        cln(4 * cont - 4);
    }
    return 0;
}