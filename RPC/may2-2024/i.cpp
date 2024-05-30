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
    ll c;
    cin >> c;
    int m;
    cin >> m;
    ll num[m];
    set<int> prime;
    uf(i, 0, m)
    {
        cin >> num[i];
        prime.insert(num[i]);
    }
    ll fact;
    uf(i, 0, m)
    {
        fact = c / num[i];
        if (num[i] < c && c == fact * num[i] && prime.find(fact) != prime.end())
        {
            (num[i] < fact) ? cout << num[i] << ' ' << fact << '\n' : cout << fact << ' ' << num[i] << '\n';
            return 0;
        }
        }
    return 0;
}