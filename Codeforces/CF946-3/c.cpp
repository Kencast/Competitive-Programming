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

int get(map<vi, int> &mapa, vi &v)
{
    if (mapa.find(v) == mapa.end())
        return 0;
    return mapa[v];
}

void sset(map<vi, int> &mapa, vi &v)
{
    if (mapa.find(v) == mapa.end())
        mapa[v] = 1;
    else
        mapa[v] += 1;
}

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
        int num[n];
        uf(i, 0, n) cin >> num[i];
        ll cont = 0;
        map<vi, int> mapa;
        uf(i, 0, n - 2)
        {
            vector<int> nor = {num[i], num[i + 1], num[i + 2]};
            vector<int> p1 = {0, num[i + 1], num[i + 2]};
            vector<int> p2 = {num[i], 0, num[i + 2]};
            vector<int> p3 = {num[i], num[i + 1], 0};
            cont += get(mapa, p1);
            cont += get(mapa, p2);
            cont += get(mapa, p3);
            cont -= get(mapa, nor) * 3;
            sset(mapa, p1);
            sset(mapa, p2);
            sset(mapa, p3);
            sset(mapa, nor);
        }
        cln(cont);
    }
    return 0;
}