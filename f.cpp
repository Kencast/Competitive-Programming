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

bool ord(vi &a)
{
  forr(i, 1, a.size()) if (a[i] < a[i - 1]) return false;
  return true;
}

int pos(int i)
{
  return (i + n) % n;
}

void solv()
{
  cin >> n;
  vi v(n);
  forn(i, n) cin >> v[i];
  if (ord(v))
  {
    cln(0);
    return;
  }
  if (n > 3)
  {
    int cont = 0;
    forn(i, n)
    {
      int x = v[pos(i - 1)], y = v[i], z = v[pos(i + 1)];
      if ((x > y || y > z) && (x < y || y < z))
        cont++;
    }
    if (cont > 1)
    {
      cln(-1);
      return;
    }
  }
  int res = 2 * n;
  lld mn = 1e9, mx = 0;
  forn(i, n) mn = min(mn, v[i]), mx = max(mx, v[i]);
  int cont1 = 0, cont2 = 0;
  vi p1 = v, p2 = v;
  while (p1.back() != mn)
  {
    cont1++;
  }
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
