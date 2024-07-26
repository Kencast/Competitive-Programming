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

bool get(int i, int j, int n, int m)
{
    if (j < 0 || j >= m)
        return false;
    if (i < 0 || i >= n)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int mat[n][m];
        int vec;
        uf(i, 0, n)
        {
            uf(j, 0, m) cin >> mat[i][j];
        }
        uf(i, 0, n)
        {
            uf(j, 0, m)
            {
                vec = 0;
                if (get(i, j + 1, n, m))
                    vec = max(vec, mat[i][j + 1]);
                if (get(i, j - 1, n, m))
                    vec = max(vec, mat[i][j - 1]);
                if (get(i - 1, j, n, m))
                    vec = max(vec, mat[i - 1][j]);
                if (get(i + 1, j, n, m))
                    vec = max(vec, mat[i + 1][j]);
                if (mat[i][j] > vec)
                    mat[i][j] = vec;
                ce(mat[i][j]);
            }
            ln;
        }
    }
    return 0;
}