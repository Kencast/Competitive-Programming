#include <bits/stdc++.h>
using namespace std;

#define uf(i, a, b) for (int i = (a); i < (b); i++)
#define df(i, a, b) for (int i = (a); i >= (b); i--)
#define cln(v) cout << v << '\n'
#define ce(v) cout << v << ' '
#define ln cout << '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pr;
typedef vector<int> vi;
typedef vector<long long> vll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, num;
    cin >> n >> m;
    int clas[n];
    uf(i, 0, n) cin >> clas[i];
    vector<pr> wp(n);
    uf(i, 0, n) cin >> num, wp[i] = {clas[i], num};
    sort(wp.begin(), wp.end());
    vi ingots(m);
    uf(i, 0, m) cin >> ingots[i];
    vi memo(2000001, 0);
    int pos = 0, best = 0;
    uf(i, 0, 2000001)
    {
        while (pos < n && wp[pos].first <= i)
        {
            if (wp[pos].first - wp[pos].second < wp[best].first - wp[best].second)
                best = pos;
            pos++;
        }
        if (i >= wp[best].first)
            memo[i] = 2 + memo[i - (wp[best].first - wp[best].second)];
    }
    ll exp = 0;
    uf(i, 0, m)
    {
        if (ingots[i] < 2000001)
        {
            exp += memo[ingots[i]];
            continue;
        }
        int cant = wp[best].first - wp[best].second;
        int inf = cant * (wp[best].first / cant) + ingots[i] % cant;
        if (wp[best].first == cant)
            inf = ingots[i] % cant;
        exp += 2 * ((ingots[i] - inf) / cant) + memo[inf];
    }
    cln(exp);
    return 0;
}