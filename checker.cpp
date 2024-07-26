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
    string s;
    int t = 1, n;
    // cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        vector<string> p;
        uf(i, 0, s.size())
        {
            if (i == 0 || s[i] <= s[i - 1])
            {
                string a;
                uf(j, 0, i + 1) a += s[j];
                df(j, i, 0) a += s[j];
                p.push_back(a);
            }
        }
        sort(p.begin(), p.end());
        cln(p[0]);
    }
    return 0;
}