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
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll sum = 0;
        uf(i, 1, n + 1) sum += i * (2 * i - 1);
        cout << sum << ' ' << 2 * n << '\n';
        df(i, n, 1)
        {
            cout << "1 " << i << ' ';
            uf(i, 1, n + 1) ce(i);
            ln;
            cout << "2 " << i << ' ';
            uf(i, 1, n + 1) ce(i);
            ln;
        }
    }
    return 0;
}