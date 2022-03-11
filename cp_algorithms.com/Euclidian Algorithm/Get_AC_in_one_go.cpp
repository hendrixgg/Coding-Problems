#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';

/* global variables */

/* global variables */

template<typename T>
T gcd(T a, T b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

void TestCase()
{
    ll a, b;
    cin >> a >> b;
    if(a == 1ll || b == 1ll)
    {
        cout << "0\n";
        return;
    }
    if(gcd(a, b) != 1ll)
    {
        cout << "-1\n";
        return;
    }
    // why the line below: https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem
    cout << a*b - a - b + 1 << nl;
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