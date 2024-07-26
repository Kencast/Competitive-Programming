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
    cin>>n;
    int day[n+1];
    int cost[n+1];
    uf(i, 0, n){
	cin>>day[i]>>cost[i];
    }
    auto cmp=[&](int a, int b){
	return cost[a]<cost[b];
    };
    priority_queue<int, vi, decltype(cmp)> cola(cmp);
    int res[n];
    day[n]=INT32_MAX;
    cost[n]=0;
    int d=day[0], pos=0;
    while(pos<=n){
	if(!cola.empty() && d<day[pos]){
		res[cola.top()]=d;
		d++;
		cola.pop();
	}
	else{
		cola.push(pos); 
		d=day[pos];
		pos++;
	}
    }
    uf(i, 0, n) ce(res[i]);
    ln;
    return 0;
}
