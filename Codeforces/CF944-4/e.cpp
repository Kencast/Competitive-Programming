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
        int n, k, q;
        cin >> n >> k >> q;
        vector<ll> point(k + 1);
        vector<ll> time(k + 1);
        point[0] = time[0] = 0;
        uf(i, 0, k) cin >> point[i + 1];
        uf(i, 0, k) cin >> time[i + 1];
        int inf, sup, m;
        ll num;
        while (q--)
        {
            cin >> num;
            inf = 0, sup = k + 1;
            while (inf + 1 < sup)
            {
                m = (inf + sup) / 2;
                (num >= point[m]) ? inf = m : sup = m;
            }
            if (inf == k)
                inf--;
            ce(time[inf] + ((time[inf + 1] - time[inf]) * (num - point[inf])) / (point[inf + 1] - point[inf]));
        }
        ln;
    }
    return 0;
}