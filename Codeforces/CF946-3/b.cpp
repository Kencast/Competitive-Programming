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
        int n;
        cin >> n;
        char w[n];
        char l[26] = {};
        uf(i, 0, n)
        {
            cin >> w[i];
            if (!l[w[i] - 'a'])
                l[w[i] - 'a'] = w[i];
        }
        int le = 0, ri = 25;
        while (le <= ri)
        {
            if (l[le] && l[ri])
                swap(l[le], l[ri]), le++, ri--;
            else
            {
                if (!l[le])
                    le++;
                if (!l[ri])
                    ri--;
            }
        }
        uf(i, 0, n)
        {
            cout << l[w[i] - 'a'];
        }
        ln;
    }
    return 0;
}