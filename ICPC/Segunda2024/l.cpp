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
    int n;
    cin >> n;
    int ar[n + 1];
    int num[n + 1];
    uf(i, 1, n + 1) cin >> ar[i], num[ar[i]] = i;
    int res = 0;
    uf(i, 1, n + 1)
    {
        if (num[i] != i)
        {
            res++;
            num[ar[i]] = num[i];
            ar[num[i]] = ar[i];
        }
    }
    uf(i, 1, n + 1) cin >> ar[i], num[ar[i]] = i;
    uf(i, 1, n + 1)
    {
        if (num[i] != i)
        {
            res++;
            num[ar[i]] = num[i];
            ar[num[i]] = ar[i];
        }
    }
    cln(res);
    return 0;
}