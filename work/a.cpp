#include <bits/stdc++.h>
#include <iomanip>
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
  int n;
  cin>>n;
  double loc[n];
  double vel[n];
  uf(i, 0, n) cin>>loc[i]>>vel[i];
  double inf=0, sup=2e9, m;
  double error=0.0000001;
  auto eval=[&](double time){
    double l=loc[0]-time*vel[0], r=loc[0]+time*vel[0];
    uf(i, 0, n){
      l=max(l, loc[i]-time*vel[i]), r=min(r, loc[i]+time*vel[i]);
    }
    return r>=l;
  };
  while(inf+error<sup){
    m=inf+(sup-inf)/2.0;
    if(eval(m)) sup=m;
    else inf=m;
  }
  if(eval(inf)) sup=inf;
  cout<<setprecision(7);
  cln(sup);
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
