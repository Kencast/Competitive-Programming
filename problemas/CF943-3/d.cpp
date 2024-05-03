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
        int n, k, pb, ps;
        cin >> n >> k >> pb >> ps;
        int k2 = k;
        pb--, ps--;
        int perm[n];
        ll points[n];
        bool visit[2][n];
        uf(i, 0, n)
        {
            cin >> perm[i], perm[i]--;
            visit[0][i] = false;
        }
        uf(i, 0, n)
        {
            cin >> points[i];
            visit[1][i] = false;
        }
        ll bod = 0, aux = 0;
        while (visit[0][pb] == false && k)
        {
            visit[0][pb] = true;
            aux += points[pb];
            k--;
            bod = max(bod, aux + points[pb] * k);
            pb = perm[pb];
        }
        ll sas = 0;
        aux = 0;
        k = k2;
        while (visit[1][ps] == false && k)
        {
            visit[1][ps] = true;
            aux += points[ps];
            k--;
            sas = max(sas, aux + points[ps] * k);
            ps = perm[ps];
        }
        if (bod > sas)
            cln("Bodya");
        else if (sas > bod)
            cln("Sasha");
        else
            cln("Draw");
    }
    return 0;
}