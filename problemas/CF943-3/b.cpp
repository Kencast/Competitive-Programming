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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k = 0;
        cin >> n >> m;
        string a, b;
        cin >> a;
        cin >> b;
        int ult = 0;
        uf(i, 0, n)
        {
            while (ult < m)
            {
                if (b[ult] == a[i])
                {
                    k++;
                    ult++;
                    break;
                }
                ult++;
            }
        }
        cln(k);
    }
    return 0;
}