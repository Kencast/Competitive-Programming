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

const int tam = 2e5;
vi adj[tam];

// Tarjan commun implementation

// Tarjan variables
vi id(tam, -1);
int scc[tam];
bool inS[tam];
stack<int> s;
int counter = 0, topo = 0;

// The number assigned to each component indicates the topological order
// In this case in descending orden, that is A before B if topo(A)>topo(B);

void tarjan(int node)
{
  id[node] = scc[node] = counter++;
  s.push(node);
  inS[node] = true;
  for (auto e : adj[node])
  {
    if (id[e] < 0)
      tarjan(e);
    if (inS[e])
      scc[node] = min(scc[node], scc[e]);
  }
  if (scc[node] != id[node])
    return;
  while (1)
  {
    int pp = s.top();
    s.pop();
    inS[pp] = false;
    scc[pp] = topo;
    if (pp == node)
      break;
  }
  topo++;
}

// Example with problem 'Giant pizza' from cses.
void solv()
{
  int n, m;
  cin >> n >> m;
  forn(i, n)
  {
    char sg;
    int a, b;
    // Node 2*i: variable i
    // Node 2*i+1: varible !i
    cin >> sg >> a;
    a = (a - 1) << 1;
    if (sg == '-')
      a++;
    cin >> sg >> b;
    b = (b - 1) << 1;
    if (sg == '-')
      b++;
    // Not a -> b
    adj[a ^ 1].push_back(b);
    // Not b -> a
    adj[b ^ 1].push_back(a);
  }
  forn(i, 2 * m) if (id[i] < 0) tarjan(i);
  forn(i, 2 * m)
  {
    if (scc[i] == scc[i ^ 1])
    {
      cln("IMPOSSIBLE");
      return;
    }
  }
  // If !X before X
  forn(i, m)(scc[i << 1] < scc[(i << 1) + 1]) ? ce('+') : ce('-');
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
