#include <bits/stdc++.h>

using namespace std;
 

using ll = long long;
using lf = double;
 
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for(int i=(n-1); i>=0; i--)
#define vec vector
#define pr pair
#define fs first
#define sd second
#define ins insert
#define ers erase
#define pb push_back
#define all(n) begin(n), end(n)


struct segment{
	vector<ll> tree;
	ll neutralNumber; // operation(a, neutralNumber)=a
	int n; //Size of the array
	
	void init(int len){
		n=len;
		neutralNumber=INT64_MAX;
		tree.assign(2*n+2, neutralNumber);
	}
	
	ll operation(ll a, ll b){
		return min(a, b);
	}

	void set(int pos, ll val){ //The array number in the leafs
		tree[n+pos]=val;
	}
	
	void build(){
		for(int i=n-1; i>0; i--){ //father=i, left child=2*i, right child=2*i+1
			tree[i]=operation(tree[i<<1], tree[(i<<1)+1]);
		}
	}
	
	void update(int pos, ll val){ // pos>=0 and pos<n
		pos+=n;
		tree[pos]=val;
		while(pos>1){
			int up=pos>>1;
			tree[up]=operation(tree[up<<1], tree[(up<<1)+1]);
			pos=up;
		}
	}
	
	ll query(int l, int r){ // query in the range [l, r)
		l+=n;
		r+=n;
		ll res=neutralNumber;
		while(l<r){
			if(l&1){
				res=operation(res, tree[l]);
				l++;
			}
			if(r&1){
				r--;
				res=operation(res, tree[r]);
			}
			l=l>>1;
			r=r>>1;
		}
		return res;
	}
};

void solv() {
	int n, m;
	cin>>n>>m;
	segment st;
	ll num;
	st.init(n);
	for(int i=0; i<n; i++) cin>>num, st.set(i, num);
	st.build();
	while(m--){
		int op;
		cin>>op;
		if(op==1){
			int pos, val;
			cin>>pos>>val;
			st.update(pos, val);
		}
		else{
			int l, r;
			cin>>l>>r;
			cout<<st.query(l, r)<<'\n';
		}
	}
}

int main() {
  solv();
  return 0;
}
