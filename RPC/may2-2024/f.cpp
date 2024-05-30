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

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int num[21] = {};
    bool ocup[21];
    int h, m = 25, cont = 0;
    uf(i, 0, n)
    {
        cin >> h;
        num[h]++;
    }
    uf(i, 0, 21)
    {
        ocup[i] = false;
        if (num[i])
        {
            cont++;
            ocup[i] = true;
            m = min(m, i);
        }
    }
    ll res = m * (num[m] - 1);
    cont--;
    ocup[m] = false;
    while (cont)
    {
        h = 31;
        uf(i, 0, 21)
        {
            if (ocup[i] && gcd(i, m) >= gcd(h, m))
                (gcd(i, m) == gcd(h, m)) ? h = min(h, i) : h = i;
        }
        res += h * (num[h] - 1);
        res += gcd(m, h);
        ocup[h] = false;
        m = h;
        cont--;
    }
    cln(res);
    return 0;
}