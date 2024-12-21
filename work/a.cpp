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

void solv()
{
    int n;
    cin >> n;
    int num[n];
    forn(i, n) cin >> num[i];
    int l = 0, r = n - 1;
    while (l < n && num[l] == 0)
        l++;
    while (r >= 0 && num[r] == 0)
        r--;
    if (l == n)
    {
        cln(0);
        return;
    }
    forr(i, l, r + 1)
    {
        if (num[i] == 0)
        {
            cln(2);
            return;
        }
    }
    cln(1);
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
