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

    ll n; cin >> n;
    vector<int> b(n);
    for(int& bi : b) cin >> bi;
    int minb = *min_element(b.begin(), b.end()), maxb = *max_element(b.begin(), b.end());
    if(minb == maxb)
    {
        cout << "0 " << n * (n-1) / 2;
        return 0;
    }
    ll cnt_min = 0, cnt_max = 0;
    for_each(b.begin(), b.end(), 
    [&](const int& bi)
    {
        cnt_min += bi == minb;
        cnt_max += bi == maxb;
    });
    cout << maxb - minb << ' ' << cnt_min * cnt_max;
    return 0;
}