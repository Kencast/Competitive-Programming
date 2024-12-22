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
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  x--;
  y--;
  char mat[h][w];
  forn(i, h) forn(j, w) cin >> mat[i][j];
  string t;
  cin >> t;
  bool vis[h][w] = {};
  map<char, ii> mapa;
  mapa['U'] = {-1, 0};
  mapa['D'] = {1, 0};
  mapa['L'] = {0, -1};
  mapa['R'] = {0, 1};
  int cont = 0;
  for (char a : t)
  {
    ii dir = mapa[a];
    x += dir.first;
    y += dir.second;
    if (mat[x][y] == '#')
      x -= dir.first, y -= dir.second;
    else if (mat[x][y] == '@' && !vis[x][y])
      cont++, vis[x][y] = true;
  }
  ce(x + 1), ce(y + 1), cln(cont);
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
