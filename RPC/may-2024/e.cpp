#include <bits/stdc++.h>
using namespace std;

#define uf(i, a, b) for (int i = (a); i < (b); i++)
#define df(i, a, b) for (int i = (a); i >= (b); i--)
#define cln(v) cout << v << '\n'
#define ce(v) cout << v << ' '
#define ln cout << '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll sumN = 0, sum = 0;
    list<pr> lista;
    ll num[n];
    uf(i, 0, k)
    {
        cin >> num[i];
        sumN += num[i], sum += num[i] * (i + 1);
    }
    lista.push_front({sum, 1});
    uf(i, k, n)
    {
        cin >> num[i];
        sum -= sumN;
        sum += num[i] * k;
        sumN -= num[i - k], sumN += num[i];
        lista.push_front({sum, i - k + 2});
    }
    lista.sort();
    for (pr r : lista)
    {
        ce(r.second);
        cln(r.first);
    }
    return 0;
}