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

typedef pr<long double, long double> ii;
typedef vec<long long> vi;
typedef vec<vec<int>> Adj;
typedef vec<vec<ii>> WAdj;
typedef long double ld;

// Problem: https://open.kattis.com/problems/monk

void solv()
{
  int a, d;
  cin >> a >> d;
  vector<ii> ast(a);      // Segments of the ascent
  vector<ii> dst(d);      // Segments of the descent
  lld maxH = 0, maxT = 0; // Height of the top and maximum time
  forn(i, a)
  {
    int h, t;
    cin >> h >> t;
    ast[i] = {t, h};
    maxH += h;
    maxT += t;
  }
  forn(i, d)
  {
    int h, t;
    cin >> h >> t;
    dst[i] = {t, h};
  }
  ld inf = 0, sup = maxT, m;
  ld err = 0.000001;
  // Function to calculate the height in the x time of the ascent
  auto afun = [&](ld x)
  {
    int sgt = 0;
    ld alt = 0, tm = 0;
    while (sgt < a && x > tm)
    {
      alt += ast[sgt].second;
      tm += ast[sgt].first;
      sgt++;
    }
    if (x >= tm)
      return alt;
    sgt--;
    alt -= ast[sgt].second;
    tm -= ast[sgt].first;
    return alt + (x - tm) * (ast[sgt].second / (ast[sgt].first));
  };
  // Function to calculate the height in the x time of the descent
  auto dfun = [&](ld x)
  {
    int sgt = 0;
    ld alt = maxH, tm = 0;
    while (sgt < d && x > tm)
    {
      alt -= dst[sgt].second;
      tm += dst[sgt].first;
      sgt++;
    }
    if (x >= tm)
      return alt;
    sgt--;
    alt += dst[sgt].second;
    tm -= dst[sgt].first;
    return alt - (x - tm) * (dst[sgt].second / (dst[sgt].first));
  };
  while (inf + err < sup)
  {
    m = (sup + inf) / 2.0;
    if (dfun(m) <= afun(m))
      sup = m;
    else
      inf = m;
  }
  cout << setprecision(8);
  cln(sup);
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
