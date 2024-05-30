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
    string s;
    while (t--)
    {
        cin >> s;
        int cont = 1;
        bool band = false;
        uf(i, 0, s.size())
        {
            if (s[i] == '1')
            {
                if (i > 0 && s[i - 1] == '0')
                    band = true, cont++;
                if (i + 1 < s.size() && s[i + 1] == '0')
                    cont++;
            }
        }
        (band) ? cln(cont - 1) : cln(cont);
    }
    return 0;
}