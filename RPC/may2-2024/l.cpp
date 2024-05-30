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
    int r, k;
    cin >> r >> k;
    int rule[8];
    int c;
    char a;
    uf(i, 0, 8)
    {
        rule[i] = r & 1;
        r >>= 1;
    }
    string actual;
    cin >> actual;
    string next = actual;
    while (k--)
    {
        uf(i, 0, actual.size())
        {
            c = 0;
            if (i > 0 && actual[i - 1] == 'X')
                c |= 4;
            if (actual[i] == 'X')
                c |= 2;
            if (i + 1 < actual.size() && actual[i + 1] == 'X')
                c |= 1;
            next[i] = (rule[c]) ? 'X' : '.';
            cout << next[i];
        }
        ln;
        swap(actual, next);
    }
    return 0;
}