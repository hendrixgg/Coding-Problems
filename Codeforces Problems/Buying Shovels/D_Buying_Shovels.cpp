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
    int n, k; cin >> n >> k;
    if(n <= k)
    {
        cout << "1\n";
        return;
    }
    vector<int> factors;
    for(int i = 1; i*i <= n && i <= k; ++i)
    {
        if(n % i == 0)
        {
            factors.push_back(i);
            if(n / i <= k)
                factors.push_back(n/i);
        }
    }
    cout << n / *max_element(factors.begin(), factors.end()) << nl;
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