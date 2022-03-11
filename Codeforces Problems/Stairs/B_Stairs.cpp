#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define PI 3.141592653589793238L
const char nl = '\n';

#define count_cells(n) ((n)*(n+1)>>1)
void TestCase()
{
    ll x, count_nice = 0; cin >> x;
    
    // nice stair case heght(n):
    // n == 1: 1
    // n >= 2: 2*nice_stair_case_height(n-1) + 1
    for(ll stair_height = 1; x > 0; stair_height = 2*stair_height + 1)
    {
        x -= count_cells(stair_height);
        count_nice += x >= 0;
    }
    cout << count_nice << nl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TTT;
    for (cin >> TTT; TTT != 0; --TTT)
        TestCase();
    
    // for(ll n = 1, h = 1, cnt = 1; cnt <= 1e18; cnt+=count_cells(2*h + 1), ++n, h = 2*h + 1)
    //     cout << n << ": " << cnt << nl;
    return 0;
}