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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        string t;
        cin >> n;
        cin >> s;
        cin >> t;
        string a = s;
        uf(i, 0, n - 2) if (s[i] == s[i + 2] == '0') t[i + 1] = '1';
        uf(i, 0, n - 2) if (t[i] == t[i + 2] == '1') s[i + 1] = '1';
        int pr[n + 1];
        pr[0] = 0;
        uf(i, 1, n + 1)(s[i] == '1') ? pr[i] = 1 + pr[i - 1] : pr[i] = pr[i - 1];
        int q, l, r;
        int res;
        cin >> q;
        while (q--)
        {
            cin >> l >> r;
            res = pr[r] - pr[l - 1];
            if (a[l - 1] == '0' && s[l - 1] == '1')
                res--;
            if (a[r - 1] == '0' && s[r - 1] == '1')
                res--;
            cln(res);
        }
    }
    return 0;
}