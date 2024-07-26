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

ll maximo(ll n)
{
    return (n & 1) ? (n - 1) * (n + 1) / 2 : n * n / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (k & 1 or k > maximo(n))
        {
            cln("NO");
            continue;
        }
        cln("YES");
        k /= 2;
        int num[n];
        uf(i, 0, n) num[i] = i + 1;
        int pos = 1;
        int N = n;
        while (k)
        {
            if (k >= n - pos)
            {
                swap(num[pos - 1], num[N - pos]);
                k -= n - pos;
                n--;
            }
            else
            {
                swap(num[pos - 1], num[k + pos - 1]);
                k = 0;
            }
            pos++;
        }
        for (int a : num)
            ce(a);
        ln;
    }
    return 0;
}