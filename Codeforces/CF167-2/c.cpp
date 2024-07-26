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
        cin >> n;
        int first[n];
        int second[n];
        uf(i, 0, n) cin >> first[i];
        uf(i, 0, n) cin >> second[i];
        int rf = 0, rs = 0;
        bool vis[n] = {};
        uf(i, 0, n)
        {
            if (first[i] == 1 && second[i] < 1)
                rf++, vis[i] = true;
            else if (second[i] == 1 && first[i] < 1)
                rs++, vis[i] = true;
            else if (max(first[i], second[i]) == 0)
                vis[i] = true;
        }
        uf(i, 0, n)
        {
            if (vis[i] == false)
            {
                if (first[i] == 1)
                    (rs < rf) ? rs++ : rf++;
                else
                    (rs < rf) ? rf-- : rs--;
            }
        }
        cln(min(rs, rf));
    }
    return 0;
}