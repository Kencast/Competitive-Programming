#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(ARG) cout << "[" << #ARG << "]: " << ARG << endl
#else
#define debug(ARG) 42
#endif

using ll = unsigned long long;

#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n - 1); i >= 0; i--)
#define vec vector
#define pr pair
#define fs first
#define sd second
#define ins insert
#define ers erase
#define pb push_back
#define all(n) begin(n), end(n)

struct segment
{
	typedef long long node;
	typedef long long ll;

private:
	vector<node> tree;
	int n;
	ll basePos;
	node neutralValue;

public:
	// Call init with maximum number of elements the segment is going to have
	// and set the neutral value of the operation.
	void init(int len)
	{
		n = len;
		ll pot = 1;
		while (pot < len)
			pot <<= 1;
		neutralValue = INT64_MAX;
		tree.assign(2 * pot, neutralValue);
		basePos = pot - 1;
	}

	// Define the operation you want, it works also when is not commutative
	node operation(node &a, node &b)
	{
		return min(a, b);
	}

	// change the value of a position of the array, pos in [0, n)
	// this doesnt update the segment tree
	void set(int pos, ll val)
	{
		// Build node if ll and node are different datatypes
		tree[basePos + pos] = val;
	}

	// Call this if you want to use set() many times and then update the segment. O(n)
	void build()
	{
		for (int i = basePos - 1; i >= 0; i--)
		{ // left child and right child
			tree[i] = operation(tree[(i << 1) + 1], tree[(i << 1) + 2]);
		}
	}

	// pos in [0, n). Updates a position, O(logn)
	void update(int pos, ll val)
	{
		set(pos, val);
		pos = basePos + pos;
		while (pos)
		{
			int up = (pos - 1) >> 1;
			tree[up] = operation(tree[(up << 1) + 1], tree[(up << 1) + 2]);
			pos = up;
		}
	}

	node query(int l, int r)
	{ // query in range [l, r)
		l += basePos;
		r += basePos;
		node ansLeft = neutralValue;
		node ansRight = neutralValue;
		while (l < r)
		{
			if (!(l & 1))
			{
				ansLeft = operation(ansLeft, tree[l]);
				l++;
			}
			if (!(r & 1))
			{
				r--;
				ansRight = operation(tree[r], ansRight);
			}
			l = (l - 1) >> 1;
			r = (r - 1) >> 1;
		}
		return operation(ansLeft, ansRight);
	}
};

void solv()
{
	int n, m;
	cin >> n >> m;
	segment st;
	ll num;
	st.init(n);
	for (int i = 0; i < n; i++)
		cin >> num, st.set(i, num);
	st.build();
	while (m--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int pos, val;
			cin >> pos >> val;
			st.update(pos, val);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << st.query(l, r) << '\n';
		}
	}
}

int main()
{
	solv();
	return 0;
}
