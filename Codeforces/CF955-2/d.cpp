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
        int n, m, k;
        cin >> n >> m >> k;
        int mat[n + 1][m + 1];
        uf(i, 1, n + 1)
        {
            uf(j, 1, m + 1) cin >> mat[i][j];
        }
        int acum[n + 1][m + 1];
        char type;
        ll sw = 0, wsw = 0;
        uf(i, 0, m + 1) acum[0][i] = 0;
        uf(i, 1, n + 1)
        {
            acum[i][0] = 0;
            uf(j, 1, m + 1)
            {
                cin >> type;
                if (type == '0')
                    acum[i][j] = acum[i - 1][j] + acum[i][j - 1] - acum[i - 1][j - 1], sw += mat[i][j];
                else
                    acum[i][j] = 1 + acum[i - 1][j] + acum[i][j - 1] - acum[i - 1][j - 1], wsw += mat[i][j];
            }
        }
        int mcm = 0;
        int countS, countW;
        for (int i = 1; i <= n - k + 1; i++)
        {
            for (int j = 1; j <= m - k + 1; j++)
            {
                countW = acum[i + k - 1][j + k - 1] - acum[i - 1][j + k - 1] - acum[i + k - 1][j - 1] + acum[i - 1][j - 1];
                countS = k * k - countW;
                if (abs(countS - countW))
                    mcm = gcd(mcm, abs(countS - countW));
            }
        }
        if (sw == wsw || (mcm && abs(sw - wsw) % mcm == 0))
            cln("YES");
        else
            cln("NO");
    }
    return 0;
}
