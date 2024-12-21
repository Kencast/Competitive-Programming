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

int n, m;
lld k;
lld dp[200][200][201];
lld mat[200][200];

lld solve(int i, int j, int x)
{
  if (i == n || j == m)
    return 1e15;
  if (dp[i][j][x] > -1)
    return dp[i][j][x];
  lld res = INT64_MAX;
  lld c1, c2;
  if (i == n - 1 && j == m - 1)
    c1 = 0, c2 = 0;
  else
  {
    c1 = solve(i + 1, j, m);
    if (x != m)
      c2 = solve(i, j + 1, x);
  }
  if (x == m)
  {
    forn(p, m)
    {
      if (i == n - 1 && j == m - 1)
        c2 = 0;
      else
        c2 = solve(i, j + 1, p);
      res = min(res, mat[i][(p + j) % m] + p * k + min(c1, c2));
    }
  }
  else
    res = min(res, mat[i][(x + j) % m] + min(c1, c2));
  return dp[i][j][x] = res;
}

lld solve2()
{
}

void solv()
{
  cin >> n >> m >> k;
  forn(i, n) forn(j, m) cin >> mat[i][j];
  forn(i, n)
  {
    forn(j, m) forn(x, m + 1) dp[i][j][x] = -1;
  }
  cln(solve(0, 0, m));
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
