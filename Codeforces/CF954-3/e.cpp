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
        int n, k;
        cin >> n >> k;
        vi num(n);
        uf(i, 0, n) cin >> num[i];
        sort(num.begin(), num.end());
        map<int, vi> group;
        uf(i, 0, n) group[num[i] % k].push_back(num[i]);
        int cont = 0, p;
        ll res = 0;
        for (pair<int, vi> g : group)
        {
            if (cont > 1)
                break;
            int pre[g.second.size() + 3];
            pre[0] = pre[1] = 0;
            uf(i, 2, g.second.size() + 1)
            {
                pre[i] = pre[i - 2] + (g.second[i - 1] - g.second[i - 2]) / k;
            }
            if (g.second.size() % 2 == 1)
            {
                cont++;
                p = INT32_MAX;
                for (int i = 2; i <= g.second.size() + 1; i += 2)
                    p = min(p, pre[g.second.size()] - pre[i - 1] + pre[i - 2]);
            }
            else
                p = pre[g.second.size()];
            res += p;
        }
        (cont < 2) ? cln(res) : cln(-1);
    }
    return 0;
}