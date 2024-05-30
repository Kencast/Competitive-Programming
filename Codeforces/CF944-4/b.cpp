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
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int i = 1;
        while (s[i] == s[0] && i < s.size())
            i++;
        if (i == s.size())
            cln("NO");
        else
        {
            swap(s[0], s[i]);
            cln("YES");
            cln(s);
        }
    }
    return 0;
}