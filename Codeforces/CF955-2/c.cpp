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
        int n, l, r;
        cin >> n >> l >> r;
        int cart[n];
        uf(i, 0, n) cin >> cart[i];
        int cont = 0;
        int ant = 0, bef = 0;
        ll a = 0;
        while (bef < n)
        {
            a += cart[bef];
            while (a > r)
                a -= cart[ant], ant++;
            if (a >= l && a <= r)
                a = 0, ant = bef + 1, cont++;
            bef++;
        }
        cln(cont);
    }
    return 0;
}