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

ll dp[801][7200];

ll solve(int cant, int sum)
{
    if (cant == 1)
        return dp[cant][sum] = 1;
    if (dp[cant][sum])
        return dp[cant][sum];
    ll total = 0;
    uf(i, 0, 10)
    {
        if (sum - i >= 0 && sum - i <= (cant - 1) * 9)
            total += solve(cant - 1, sum - i);
    }
    return dp[cant][sum] = total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll res = 0, r;
        for (int s = 1; s <= 9 * n; s++)
        {
            r = 0;
            uf(i, 1, 10)
            {
                if (s - i >= 0 && s - i <= (n - 1) * 9)
                    r += solve(n - 1, s - i);
            }
            res += r * (r - 1);
        }
        cln(res);
    }
    return 0;
}