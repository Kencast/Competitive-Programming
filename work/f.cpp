#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(ARG) cout << "[" << #ARG << "]: " << ARG << endl
#else
#define debug(ARG) 42
#endif

using llu = unsigned long long;
using lld = long long;
using lf = double long;

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
  lf x[n];
  lf y[n];
  lf may = 0;
  forn(i, n)
  {
    cin >> x[i];
    cin >> y[i];
    may = max(may, y[i]);
  }
  auto eval = [&](lf h)
  {
    forr(i, 1, n)
    {
      if ((y[i - 1] - h) * x[i] >= ((y[i] - h) * x[i - 1]))
        return false;
    }
    return true;
  };
  if (eval(0))
  {
    cln(-1);
    return;
  }
  lf inf = 0.0, sup = may + 1, m;
  forn(it, 61)
  {
    m = (inf + sup) / 2.0;
    if (eval(m))
      sup = m;
    else
      inf = m;
  }
  cout << fixed << setprecision(15);
  cout << inf << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--)
    solv();
  return 0;
}
