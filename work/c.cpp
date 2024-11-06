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
	vector<int> counter;
	ll neutralNumber; // operation(a, neutralNumber)=a
	int n; //Size of the array
	
	void init(int len){
		n=len;
		neutralNumber=INT64_MAX;
		tree.assign(2*n+2, neutralNumber);
		counter.assign(2*n+2, 1);
	}
	
	void operation(int up, int i, int j){
		if(tree[i]==tree[j]) tree[up]=tree[i], counter[up]=counter[i]+counter[j];
		else if(tree[i]<tree[j]) tree[up]=tree[i], counter[up]=counter[i];
		else tree[up]=tree[j], counter[up]=counter[j];
	}

	void set(int pos, ll val){ //The array number in the leafs
		tree[n+pos]=val;
	}
	
	void build(){
		for(int i=n-1; i>0; i--){ //father=i, left child=2*i, right child=2*i+1
			operation(i, i<<1, (i<<1)+1);
		}
	}
	
	void update(int pos, ll val){ // pos>=0 and pos<n
		pos+=n;
		tree[pos]=val;
		while(pos>1){
			int up=pos>>1;
			operation(up, up<<1, (up<<1)+1);
			pos=up;
		}
	}
	
	void query(int l, int r){ // query in the range [l, r)
		l+=n;
		r+=n;
		pair<ll, ll> res={INT64_MAX, 0};
		while(l<r){
			if(l&1){
				if(tree[l]<res.first) res.first=tree[l], res.second=counter[l];
				else if(tree[l]==res.first) res.second+=counter[l];
				l++;
			}
			if(r&1){
				r--;
				if(tree[r]<res.first) res.first=tree[r], res.second=counter[r];
				else if(tree[r]==res.first) res.second+=counter[r];
			}
			l=l>>1;
			r=r>>1;
		}
		cout<<res.first<<' '<<res.second<<'\n';
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
			st.query(l, r);
		}
	}
}

int main() {
  solv();
  return 0;
}
