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
        int x, y;
        cin >> x >> y;
        int a = 0, b = 0;
        bool band = false;
        while (abs(y) < 100)
        {
            if (x > a)
                a++;
            else if (a > x)
                a--;
            if (y > b)
                b++;
            else if (y < b)
                b--;
            if (a == x && b == y)
            {
                band = true;
                break;
            }
            y--;
        }
        (band) ? cln("YES") : cln("NO");
    }
    return 0;
}