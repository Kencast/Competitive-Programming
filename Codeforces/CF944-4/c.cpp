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
        vector<int> num(4);
        int puntos[4];
        uf(i, 0, 4)
        {
            cin >> num[i];
            puntos[i] = num[i];
        }
        sort(num.begin(), num.end());
        bool band = false;
        uf(i, 0, 3)
        {
            if (min(puntos[0], puntos[1]) == num[i] && max(puntos[0], puntos[1]) == num[i + 1])
                band = true;
        }
        uf(i, 0, 3)
        {
            if (min(puntos[2], puntos[3]) == num[i] && max(puntos[2], puntos[3]) == num[i + 1])
                band = true;
        }
        (band) ? cln("NO") : cln("YES");
    }
    return 0;
}