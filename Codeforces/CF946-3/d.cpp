#include <bits/stdc++.h>
using namespace std;

#define uf(i, a, b) for (int i = (a); i < (b); i++)
#define df(i, a, b) for (int i = (a); i >= (b); i--)
#define cln(v) cout << v << '\n'
#define ce(v) cout << v << ' '
#define ln cout << '\n'
#define Inf 5LL * INT32_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pr;
typedef vector<ll> vll;

ll m, salary;
ll info[50][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> salary;
        ll totalHs = 0;
        uf(i, 0, m)
        {
            // Cost>>Happiness
            cin >> info[i][0] >> info[i][1];
            totalHs += info[i][1];
        }
        vector<vll> memo(2, vll(totalHs + 1, Inf));
        memo[1][0] = 0;
        ll ant, act;
        for (ll mes = 0; mes < m; mes++)
        {
            act = mes & 1, ant = !act;
            for (ll hs = 0; hs <= totalHs; hs++)
            {
                memo[act][hs] = memo[ant][hs];
                if (hs - info[mes][1] >= 0 && memo[ant][hs - info[mes][1]] + info[mes][0] <= mes * salary)
                {
                    memo[act][hs] = min(memo[act][hs], info[mes][0] + memo[ant][hs - info[mes][1]]);
                }
            }
        }
        int res = 0;
        uf(i, 0, totalHs + 1) if (memo[act][i] < Inf) res = max(res, i);
        cln(res);
    }
    return 0;
}