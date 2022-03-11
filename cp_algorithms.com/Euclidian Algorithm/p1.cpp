#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define PI 3.141592653589793238L
constexpr char nl = '\n';

/* global variables */

/* global variables */

/*
returns the gcd(a, b) and at the same time, solves the linear combination: 

a*x + b*y = gcd(a, b)
such that |x| + |y| is minimal and x <= y.
*/
int gcd2(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b, x, y, d;
    while(!cin.eof())
    {
        cin >> a >> b;
        d = gcd2(a, b, x, y);
        cout << x << ' ' << y << ' ' << d << nl;
    }

    return 0;
}