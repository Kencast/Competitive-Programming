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
        int n;
        cin >> n;
        vector<int> num(n);
        uf(i, 0, n) cin >> num[i];
        sort(num.begin(), num.end());
        int pos = 0, cont = 0, a = 1;
        while (pos < n)
        {
            if (num[pos] > a)
                break;
            if (num[pos] == a)
                cont++, a++;
            pos++;
        }
        if (pos < n)
            (cont & 1) ? cln("Bob") : cln("Alice");
        else
            (cont & 1) ? cln("Alice") : cln("Bob");
    }
    return 0;
}