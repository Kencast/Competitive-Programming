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

// Strongly connected components of a directed graph

const int tam = 1e5;
// Adjacency list
vi adj[tam];
// Secuencial Id of a node
int dfs_num[tam];
// Minimum a id that can be reached form a node
int dfs_low[tam];
// To see if it's on the stack
bool inStack[tam];
stack<int> s;
int counter = 1, components = 0;

void dfs(int node)
{
  dfs_num[node] = dfs_low[node] = counter++;
  s.push(node);
  inStack[node] = true;
  for (auto e : adj[node])
  {
    if (!dfs_num[e])
      dfs(e);
    if (inStack[e])
      dfs_low[node] = min(dfs_low[node], dfs_low[e]);
  }
  if (dfs_low[node] != dfs_num[node])
    return;
  components++;
  while (1)
  {
    int u = s.top();
    s.pop();
    inStack[u] = false;
    dfs_low[u] = components;
    if (u == node)
      break;
  }
}

void solv()
{
  int n, m;
  cin >> n >> m;
  while (m--)
  {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
  }
  // For i in [0, n)
  forn(i, n)
  {
    if (!dfs_num[i])
      dfs(i);
  }
  cln(components);
  forn(i, n) ce(dfs_low[i]);
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
