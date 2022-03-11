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
    // uncomment freopen statements to submit
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, not_neg = 0, not_pos = 0;
    cin >> n;
    vector<int> t(n);
    for(int& ti : t)
    {
        cin >> ti;
        not_pos += ti<=0;
    }
    not_pos -= t[0]<=0;
    int ans = 1e9;
    for(int i = 0; i+1 < n; ++i)
    {
        not_neg += t[i]>=0;
        ans = min(ans, not_neg + not_pos);
        not_pos -= t[i+1]<=0;
    }
    cout << ans;
    return 0;
}