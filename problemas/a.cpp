#include <bits/stdc++.h>
using namespace std;

#define uf(i, a, b) for(int i=(a); i<(b); i++)
#define df(i, a, b) for(int i=(a); i>=(b); i--)
#define cln(v) cout<<v<<'\n'
#define ce(v) cout<<v<<' '
#define ln cout<<'\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pr;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

__gnu_pbds::tree<int, __gnu_pbds::null_type, greater<int>, __gnu_pbds::rb_tree_tag,
 __gnu_pbds::tree_order_statistics_node_update> ost; //ordered set

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pr> num;
        num.assign(n, {});
        uf(i, 0, n){
            cin>>num[i].second>>num[i].first;
        }
        sort(num.begin(), num.end());
        ll res=0;
        ost.clear();
        uf(i, 0, n){
            res+=ost.order_of_key(num[i].second);
            ost.insert(num[i].second);
        }
        cln(res);
    }    
    return 0;
}