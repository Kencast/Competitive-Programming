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

// Problem: Restaurant orders
// Link: https://open.kattis.com/problems/orders
// Yet another knapsack

int ord[100];
vector<vector<int>> dp(100, vector<int>(30001, -1));
int n;
list<int> res;
bool amb;

int cal(int pos, int s)
{
  if (!s)
    return 0;
  if (s < 0)
    return 1000;
  if (pos == n)
    return s;
  if (dp[pos][s] != -1)
    return dp[pos][s];
  return dp[pos][s] = min(cal(pos, s - ord[pos]), cal(pos + 1, s));
}

void show(int pos, int s)
{
  if (!s)
    return;
  if (cal(pos, s - ord[pos]) == cal(pos + 1, s))
  {
    amb = true;
    return;
  }
  if (cal(pos, s - ord[pos]) == 0)
  {
    res.push_back(pos + 1);
    return show(pos, s - ord[pos]);
  }
  show(pos + 1, s);
}

void solv()
{
  cin >> n;
  forn(i, n) cin >> ord[i];
  int m;
  cin >> m;
  while (m--)
  {
    int s;
    cin >> s;
    if (cal(0, s))
      cln("Impossible");
    else
    {
      res.clear();
      amb = false;
      show(0, s);
      if (amb)
        cln("Ambiguous");
      else
      {
        for (auto a : res)
          ce(a);
        ln;
      }
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
