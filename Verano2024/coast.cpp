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
  int n, m;
  cin >> n >> m;
  vector<vi> mat(n + 2, vi(m + 2, 0));
  bool vis[n + 2][m + 2] = {};
  forn(i, n)
  {
    char p;
    forn(j, m)
    {
      cin >> p;
      if (p == '1')
        mat[i + 1][j + 1]++;
    }
  }
  auto valid = [&](int i, int j)
  {
    return i >= 0 && i <= n + 1 && j >= 0 && j <= m + 1;
  };
  stack<ii> pila;
  vis[0][0] = true;
  pila.push({0, 0});
  int posx[] = {0, 0, 1, -1};
  int posy[] = {-1, 1, 0, 0};
  lld res = 0;
  while (!pila.empty())
  {
    ii pos = pila.top();
    pila.pop();
    forn(p, 4)
    {
      int x = pos.first + posx[p], y = pos.second + posy[p];
      if (!valid(x, y))
        continue;
      if (mat[x][y])
        res++;
      else if (!vis[x][y])
        vis[x][y] = true, pila.push({x, y});
    }
  }
  cln(res);
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
