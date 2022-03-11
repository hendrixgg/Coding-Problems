#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define PI 3.141592653589793238L
const char nl = '\n';

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vector<bool> cat(n+1);
    vector<vector<int>> tree(n+1, vector<int>());
    for(int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        cat[i] = (x==1);
    }
    for(int i = 0, a, b; i < n-1; ++i)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    // debug() << imie(tree);
    // debug() << imie(cat);
    function<int(int, int, int)> dfs = [&](int cats, int parent, int at)
    {
        if(at != 1 && tree[at].size() == 1)
            return 1;
        int valid_paths = 0;
        for(const int& adj : tree[at])
        {
            if(adj == parent || cat[adj]*(cats+1) > m) continue;
            valid_paths += dfs(cat[adj]*(cats+1), at, adj);
        }
        return valid_paths;
    };
    cout << dfs(cat[1], 0, 1);
    return 0;
}