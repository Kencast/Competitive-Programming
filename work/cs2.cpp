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
  vector<vi> adj(n, vi());
  forn(i, m)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vi vis(n, -1);
  int final = -1, start;
  stack<int> pila;
  forn(i, n)
  {
    if (final != -1)
      break;
    if (vis[i] != -1)
      continue;
    pila.push(i);
    vis[i] = i;
    while (pila.size() && final == -1)
    {
      int node = pila.top();
      pila.pop();
      for (auto h : adj[node])
      {
        if (vis[h] != -1 && vis[node] != h)
        {
          final = h;
          start = vis[h];
          vis[h] = node;
          break;
        }
        if (vis[h] == -1)
        {
          pila.push(h);
          vis[h] = node;
        }
      }
    }
  }
  if (final == -1)
  {
    cln("IMPOSSIBLE");
    return;
  }
  vi res = {start};
  while (true)
  {
    res.push_back(final);
    if (final == start)
      break;
    final = vis[final];
  }
  cln(res.size());
  for (auto a : res)
    ce(a + 1);
  ln;
}

int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(0);
  int t = 1;
  while (t--)
    solv();
  return 0;
}
