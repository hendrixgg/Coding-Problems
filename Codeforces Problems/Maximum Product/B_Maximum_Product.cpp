#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define PI 3.141592653589793238L
const char nl = '\n';

void TestCase()
{
    int n; cin >> n;
    vector<ll> a(n);
    for(ll& ai : a)
        cin >> ai;
    sort(a.begin(), a.end());
    ll ans = -LLINF;
    for(int mask = 0; mask < (1<<5); ++mask)
    {
        ll prod = 1;
        for(int i = 0, l = 0, r = n-1; i < 5; ++i)
        {
            if(mask&(1<<i))
            {
                // multiply by the biggest element
                prod *= a[r];
                --r;
            }
            else
            {
                // multiply by the smallest element
                prod *= a[l];
                ++l;
            }
        }
        ans = max(ans, prod);
    }
    cout << ans << nl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TTT;
    for (cin >> TTT; TTT != 0; --TTT)
        TestCase();
    return 0;
}