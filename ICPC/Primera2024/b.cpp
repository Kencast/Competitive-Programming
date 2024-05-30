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
typedef vector<ll> vl;
ll mod=1000000007;

vector<vl> mulMat(vector<vl> & a, vector<vl> &  b){
	int fa=a.size(), k=a[0].size(), cb=b[0].size();
	vector<vl> res(fa, vl(cb));
	uf(f, 0, fa){
		uf(c, 0, cb){
			uf(i, 0, k) res[f][c]+=a[f][i]*b[i][c], res[f][c]%=mod;
		}
	}
	return res;
}

vector<vl> elevar(vector<vl>  mat, ll n){
	int tam=mat.size();
	vector<vl> ident(tam, vl(tam));
	uf(i, 0, tam){
		ident[i][i]=1;
	}
	while(n){
		if(n&1) ident=mulMat(ident, mat);
		mat=mulMat(mat, mat);
		n>>=1;
	}
	return ident;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    vector<vl> mat(7, vl(7));
    mat[0][3]=1;
    mat[3][0]=1;
    mat[0][5]=mat[5][0]=1;
    mat[3][6]=mat[6][3]=1;
    auto resp=elevar(mat, t);
    uf(i, 0, 7)
    {
        uf(j, 0, 7){
	ce(resp[i][j]);
	}
	ln;
    }
    // while(t--){

    // }
    return 0;
}
