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
        int k, q;
        cin >> k >> q;
        int minn = 150, m;
        uf(i, 0, k) cin >> m, minn = min(minn, m);
        while (q--)
        {
            cin >> m;
            ce(min(m, minn - 1));
        }
        ln;
    }
    return 0;
}