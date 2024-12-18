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

struct segment
{
  typedef long long node;
  typedef long long ll;

private:
  // Segment tree for the updates
  vector<node> treeMod;
  // Segment tree for the queries
  vector<node> treeQuery;
  int n;
  ll basePos;
  // Neutral value for the operation of updates
  node neutralMod;
  // Neutral value for the operation of queries
  node neutralQuery;

public:
  // Call init with maximum number of elements the segment is going to have
  // and set the neutral values of the operations.
  void init(int len)
  {
    n = len;
    ll pot = 1;
    while (pot < len)
      pot <<= 1;
    neutralQuery = 0;
    neutralMod = 0;
    treeMod.assign(2 * pot, neutralMod);
    treeQuery.assign(2 * pot, neutralQuery);
    basePos = pot - 1;
  }

  // Operation of the queries, it can be commutative
  node opQuery(node &a, node &b)
  {
    return a + b;
  }

  // Operation of the updates, it can be commutative.
  // It has to be distributive relative to opQuery
  node opMod(node &a, node &b)
  {
    return a + b;
  }

  // change the value of a position of the array, pos in [0, n)
  // this doesnt update the segment tree
  void set(int pos, ll val)
  {
    // Build node if ll and node are different datatypes
    treeQuery[basePos + pos] = val;
  }

  // Call this if you want to use set() many times and then update the segment. O(n)
  void build()
  {
    for (int i = basePos - 1; i >= 0; i--)
    { // left child and right child
      treeQuery[i] = opQuery(treeQuery[(i << 1) + 1], treeQuery[(i << 1) + 2]);
    }
  }

  // Propagate the changes
  void push(int act, int l, int r)
  {
    if (treeMod[act] == neutralMod)
      return;
    // To make the sum operation distributive
    ll dist = treeMod[act] * (r - l);
    treeQuery[act] = opMod(treeQuery[act], dist);
    if (act < basePos)
    {
      int left = (act << 1) + 1, right = left + 1;
      treeMod[left] = opMod(treeMod[left], treeMod[act]);
      treeMod[right] = opMod(treeMod[right], treeMod[act]);
    }
    treeMod[act] = neutralMod;
  }

  void updateRange(int act, ll val, int tl, int tr, int l, int r)
  {
    push(act, tl, tr);
    if (tr <= l || tl >= r)
      return;
    if (tl >= l && tr <= r)
    {
      treeMod[act] = opMod(treeMod[act], val);
      push(act, tl, tr);
      return;
    }
    int left = (act << 1) + 1, right = left + 1, mid = (tl + tr) >> 1;
    updateRange(left, val, tl, mid, l, r);
    updateRange(right, val, mid, tr, l, r);
    treeQuery[act] = opQuery(treeQuery[left], treeQuery[right]);
  }

  // Update the range [l, r) with the value 'val'
  void updateRange(int l, int r, ll val)
  {
    updateRange(0, val, 0, basePos + 1, l, r);
  }

  node query(int act, int tl, int tr, int l, int r)
  {
    if (tr <= l || tl >= r)
      return neutralQuery;
    push(act, tl, tr);
    if (tl >= l && tr <= r)
      return treeQuery[act];
    int left = (act << 1) + 1, right = left + 1, mid = (tl + tr) >> 1;
    node ansL = query(left, tl, mid, l, r);
    node ansR = query(right, mid, tr, l, r);
    return opQuery(ansL, ansR);
  }

  // Query in range [l, r)
  node query(int l, int r)
  {
    return query(0, 0, basePos + 1, l, r);
  }
};

// Example
void solv()
{
  int n, m;
  cin >> n >> m;
  segment st;
  st.init(n);
  forn(i, n) st.set(i, 0);
  st.build();
  while (m--)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      int l, r, v;
      cin >> l >> r >> v;
      st.updateRange(l, r, v);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      cln(st.query(l, r));
    }
  }
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
