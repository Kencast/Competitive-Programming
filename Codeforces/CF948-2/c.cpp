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

int probar(vi &num, int n, int m)
{
    int c = 0;
    int r = 1;
    uf(j, 0, n) if (m % num[j] == 0) c++, r = lcm(r, num[j]);
    return (r == m) ? c : 0;
}

void solve(vi &num, int n)
{
    map<int, int> cont;
    int res = 0, c;
    uf(i, 0, n)
    {
        cont[num[i]] += 1;
        if (num[n - 1] % num[i])
        {
            cln(n);
            return;
        }
    }
    for (int i = 2; i * i <= num[n - 1]; i++)
    {
        if (cont.find(i) == cont.end())
            res = max(res, probar(num, n, i));
        if (cont.find(num[n - 1] / i) == cont.end())
            res = max(res, probar(num, n, num[n - 1] / i));
    }
    cln(res);
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
        vector<int> num(n);
        uf(i, 0, n)
        {
            cin >> num[i];
        }
        sort(num.begin(), num.end());
        solve(num, n);
    }
    return 0;
}