#include <bits/stdc++.h>
using namespace std;

#define uf(i, a, b) for (int i = (a); i < (b); i++)
#define df(i, a, b) for (int i = (a); i >= (b); i--)
#define cln(v) cout << v << '\n'
#define ce(v) cout << v << ' '
#define ln cout << '\n'
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pr;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef list<int> li;

void solve(){
	int n, k;
	cin>>n>>k;
	double a[n];
	double b[n];
	int ind[n];
	uf(i, 0, n){
		cin>>a[i]>>b[i];
		ind[i]=i;
	}
	//sort(ind, ind+n, [&](int i, int j){
	//		return a[i]-b[i]>a[j]-b[j];
	//});
	double inf=0, sup=1e5+10, m, err=0.000001;
	auto cmp=[&](int i, int j){
		return a[i]-b[i]*m>a[j]-b[j]*m;
	};
	auto eval=[&](){
		double sum=0;
		sort(ind, ind+n, cmp);
		uf(i, 0, k) sum+=a[ind[i]]-b[ind[i]]*m;
		return sum>=0;
	};
	while(inf+err<sup){
		m=(inf+sup)/2.0;
		if(eval()) inf=m;
		else sup=m;
	}
	m=sup;
	if(eval()) inf=sup;
	cout<<setprecision(7);
	cln(inf);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while (t--)
    {
	    solve();
    }
    return 0;
}
