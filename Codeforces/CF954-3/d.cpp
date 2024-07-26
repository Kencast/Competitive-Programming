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

string s;

ll solve(int n, int pos)
{
    vi num(n - 1);
    uf(i, 0, n - 1)
    {
        if (i == pos)
            num[i] = (s[i] - '0') * 10 + (s[i + 1] - '0');
        else
            (i < pos) ? num[i] = s[i] - '0' : num[i] = s[i + 1] - '0';
    }
    ll res = 0;
    bool z = false;
    uf(i, 0, n - 1)
    {
        if (num[i] != 1)
            res += num[i];
        if (!num[i])
            z = true;
    }
    return (z) ? 0 : max(1LL, res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin >> s;
        if (n == 2)
            (s[0] == '0') ? cln(s[1]) : cln(s);
        else
        {
            ll resp = INT64_MAX;
            uf(i, 0, n - 1) resp = min(resp, solve(n, i));
            cln(resp);
        }
    }
    return 0;
}