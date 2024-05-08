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
    string a, b;
    cin >> a;
    cin >> b;
    int i = 1, j = b.size() - 2;
    int l[26] = {};
    l[0] = 1, l['e' - 'a'] = 1;
    l['i' - 'a'] = 1, l['o' - 'a'] = 1;
    l['u' - 'a'] = 1;
    while (a[i])
    {
        if (l[a[i] - 'a'])
            break;
        i++;
    }
    while (j > 0)
    {
        if (l[b[j] - 'a'])
            break;
        j--;
    }
    uf(p, 0, i) cout << a[p];
    if (l[b[j] - 'a'] == 0)
        (l[a[i] - 'a']) ? cout << a[i] : cout << 'o';
    uf(p, j, b.size()) cout << b[p];
    ln;
    return 0;
}