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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    int esc[m + 1] = {};
    int est[n][3];
    int f = 0, s = 0;
    uf(i, 0, n)
    {
        cin >> est[i][0] >> est[i][1];
        est[i][2] = 0;
        if (esc[est[i][0]] < c)
        {
            esc[est[i][0]]++, est[i][2] = 1;
            f++;
        }
    }
    uf(i, 0, n)
    {
        if (est[i][2] == 0 && esc[est[i][1]] < c)
        {
            esc[est[i][1]]++;
            s++;
        }
    }
    ce(f), cln(s);
    return 0;
}