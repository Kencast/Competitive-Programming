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
  int n;
  cin >> n;
  int freq[n] = {};
  list<int> bob;
  vi dist(n, -1);
  set<int> st;
  forn(i, n)
  {
    int num;
    cin >> num;
    num--;
    freq[num]++;
    st.insert(num);
  }
  int res = 0, turn = 0, ali = 0;
  for (auto a : st)
  {
    dist[a] = ali - freq[a];
    if (dist[a] >= 0)
      bob.push_back(a);
    ali++;
  }
  auto cmp = [&](int i, int j)
  {
    return freq[i] < freq[j];
  };
  bob.sort(cmp);
  ali = 0;
  forn(i, n)
  {
    if (!turn)
    {
      while (ali < n && !freq[ali])
        ali++;
      if (ali == n)
        break;
      res++;
      int aux = ali, pasos = 0;
      while (aux < n)
      {
        if (!freq[aux])
        {
          aux++;
          continue;
        }
        dist[aux] = pasos - freq[aux];
        aux++;
        pasos++;
      }
      // ce("Alice:"), cln(ali + 1);
      freq[ali] = 0;
    }
    else
    {
      while (bob.size() && (!freq[bob.front()] || dist[bob.front()] < 0))
        bob.pop_front();
      if (!bob.size())
        break;
      // ce("Bob:"), cln(bob.front() + 1);
      freq[bob.front()]--;
    }
    turn ^= 1;
  }
  cln(res);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solv();
  return 0;
}
