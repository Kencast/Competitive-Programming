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
        string a, b;
        cin >> a;
        cin >> b;
        if (a == b)
        {
            cln(a.size());
            continue;
        }
        int res = 0;
        int pos;
        uf(i, 0, b.size())
        {
            pos = i;
            uf(j, 0, a.size()) if (a[j] == b[pos]) pos++;
            res = max(res, pos - i);
        }
        cln(a.size() + b.size() - res);
    }
    return 0;
}