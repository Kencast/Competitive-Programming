#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> //The trees-based structures
#include <ext/pb_ds/tree_policy.hpp> //Extra operations for nodes

__gnu_pbds::tree<int, __gnu_pbds::null_type, greater<int>, __gnu_pbds::rb_tree_tag,
 __gnu_pbds::tree_order_statistics_node_update> st;

/*
Arguments
1. Type of data
2. The mapped policy. null_type to use it as a set, otherwise as a map
3. Comparison function. Less for ascendent order, great for descendent order
4. Type of tree:
rb_tree_tag=red black tree
splay_tree_tag=splay tree

5. It is included in tree_policy.hpp and contains various operations
for updating the node variants of a tree-based container, 
so we can keep track of metadata like the number of nodes in a subtree.

*/