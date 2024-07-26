// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[])
{
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(1, 40);
    cout << n << '\n';
    vector<pair<int, int>> num(n);
    for (int i = 0; i < n; i++)
    {
	    num[i]={rand(5, 20), rand(1, 100)};
    }
    sort(num.begin(), num.end());
    for(int j=0; j<n; j++) cout<<num[j].first<<' ', cout<<num[j].second<<'\n';
    return 0;
}
