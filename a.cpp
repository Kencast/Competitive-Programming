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
        int n, num;
        cin >> n;
        int len[101] = {};
        uf(i, 0, n)
        {
            cin >> num;
            len[num]++;
        }
        int cont = 0;
        uf(i, 1, 101)
        {
            if (len[i] > 2)
            {
                cont += len[i] / 3;
            }
        }
        cln(cont);
    }
    return 0;
}