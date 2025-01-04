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

// Problem: ICPC Team selection
// Link: https://open.kattis.com/problems/icpcteamselection

void solv()
{
    int n;
    cin >> n;
    list<int> disp;
    int num;
    forn(i, 3 * n) cin >> num, disp.push_back(num);
    disp.sort();
    lld res = 0;
    while (disp.size())
    {
        disp.pop_back();
        res += disp.back();
        disp.pop_back();
        disp.pop_front();
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