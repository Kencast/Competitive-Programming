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
        int x, y;
        cin >> x;
        vector<int> num;
        while (x)
        {
            if (x & 1)
            {
                if ((x >> 1) & 1)
                    num.push_back(-1), x = (x >> 1) + 1;
                else
                    num.push_back(1), x >>= 1;
            }
            else
                num.push_back(0), x >>= 1;
        }
        cln(num.size());
        for (int a : num)
            ce(a);
        ln;
    }
    return 0;
}