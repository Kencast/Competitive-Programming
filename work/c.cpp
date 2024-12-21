#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(ARG) cout << "[" << #ARG << "]: " << ARG << endl
#else
#define debug(ARG) 42
#endif

using llu = unsigned long long;
using lld = long long;
using lf = double;

#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n - 1); i >= 0; i--)
#define vec vector
#define pr pair
#define fs first
#define sd second
#define ins insert
#define ers erase
#define pb push_back
#define all(n) begin(n), end(n)
#define cln(a) cout << a << '\n'
#define ce(a) cout << a << ' '
#define ln cout << '\n'

typedef pr<long long, long long> ii;
typedef vec<long long> vi;
typedef vec<vec<int>> Adj;
typedef vec<vec<ii>> WAdj;

int n;

int nt(int a)
{
    if (a + 1 == n)
        return 0;
    return a + 1;
}

int bef(int a)
{
    if (a - 1 < 0)
        return n - 1;
    return a - 1;
}
void solv()
{
    int x, y;
    cin >> n >> x >> y;
    x--;
    y--;
    int c[n];
    forn(i, n) c[(x + i) % n] = i % 2;
    if (n % 2 || c[x] == c[y])
        c[x] = 2;
    forn(i, n) ce(c[i]);
    ln;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solv();
    return 0;
}
