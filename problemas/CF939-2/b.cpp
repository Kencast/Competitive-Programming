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
    int t, n, num;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int tengo = 0;
        int tiene = 0;
        int esta[n + 1] = {};
        uf(i, 0, n)
        {
            cin >> num;
            esta[num]++;
        }
        uf(i, 1, n + 1)
        {
            if (esta[i] == 2)
                tengo++;
            if (esta[i] == 0)
                tiene++;
        }
        if (tengo > tiene)
            cln(tengo + (tengo - tiene) * 2);
        else
            cln(tengo);
    }
    return 0;
}