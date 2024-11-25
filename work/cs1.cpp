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
  stack<int> pila;
  int color[n] = {};
  forn(i, n)
  {
    if (color[i])
      continue;
    pila.push(i);
    color[i] = 1;
    while (pila.size())
    {
      int node = pila.top();
      pila.pop();
      for (int h : adj[node])
      {
        if (color[h] == color[node])
        {
          cln("IMPOSSIBLE");
          return;
        }
        if (!color[h])
        {
          pila.push(h);
          color[h] = (color[node] == 1) ? 2 : 1;
        }
      }
    }
  }
  forn(i, n) ce(color[i]);
  ln;
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
