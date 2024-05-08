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
    int n;
    cin >> n;
    int num[n];
    uf(i, 0, n) cin >> num[i];
    int cont[n];
    cont[n - 1] = 1;
    int may = 1;
    df(i, n - 2, 0)
    {
        (num[i] < num[i + 1]) ? cont[i] = 1 + cont[i + 1] : cont[i] = 1;
        may = max(may, cont[i]);
    }
    cln(may);
    return 0;
}