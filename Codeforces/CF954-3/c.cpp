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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> ind(m);
        uf(i, 0, m) cin >> ind[i];
        string c;
        cin >> c;
        sort(ind.begin(), ind.end());
        sort(c.begin(), c.end());
        int ci = 0;
        uf(i, 0, m)
        {
            if (i + 1 < m && ind[i] == ind[i + 1])
                continue;
            s[ind[i] - 1] = c[ci];
            ci++;
        }
        cln(s);
    }
    return 0;
}