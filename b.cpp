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
        int n, k;
        cin >> n >> k;
        int bit[32] = {};
        int c = 0, last = 0;
        int num = k, p;
        p = k;
        while (p)
        {
            if (p & 1)
                bit[c]++, last = max(last, c);
            c++;
            p >>= 1;
        }
        c = (1 << last);
        num -= c;
        uf(i, 0, last)
        {
            p = (1 << i);
            if (bit[i] == 0 && c >= p)
            {
                bit[i] = 1;
                c -= p;
                num += p;
            }
        }
        if (n == 1)
            cln(k);
        else
        {
            cout << num << ' ' << c;
            uf(i, 0, n - 2) cout << " 0";
            ln;
        }
    }
    return 0;
}