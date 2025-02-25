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

// Problem: https://open.kattis.com/problems/crypto

void solv()
{
  lld n;
  cin >> n;
  lld fact = 2;
  // In res the prime number with the greatest pot(frecuency)
  lld res = n, pot = 1, cont = 0;
  while (fact * fact <= n)
  {
    while (n % fact == 0)
      cont++, n /= fact;
    if (cont > pot || (cont == pot && fact < res))
    {
      res = fact;
      pot = cont;
    }
    cont = 0;
    fact++;
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
