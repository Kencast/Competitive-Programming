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
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int num[n - 1];
        uf(i, 0, n - 1) cin >> num[i];
        int st = 1001;
        ce(st);
        uf(i, 0, n - 1)
        {
            st += num[i];
            ce(st);
        }
        ln;
    }
    return 0;
}