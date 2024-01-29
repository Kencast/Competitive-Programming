#include <iostream>
using namespace std;

int dir[4];

string solve(int h, int w){
    if(dir[0]>=dir[2]) return "Draw\n";
    int t=abs(dir[0]-dir[2])/2;
    if(abs(dir[0]-dir[2])%2==1){
        if(dir[1]==dir[3]) return "Alice\n";
        if(min(w, dir[1]+t+1)<min(w, dir[3]+t) || max(1, dir[1]-t-1)>max(1, dir[3]-t)) return "Draw\n";
        return "Alice\n";
    }
    if(dir[1]==dir[3]) return "Bob\n";
    if(min(w, dir[3]+t)<min(w, dir[1]+t) || max(1, dir[3]-t)>max(1, dir[1]-t)) return "Draw\n";
    return "Bob\n"; 
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, h, w;
    cin>>t;
    while(t--){
        cin>>h>>w;
        for(int i=0; i<4; i++) cin>>dir[i];
        cout<<solve(h, w); 

    }
    return 0;
}
