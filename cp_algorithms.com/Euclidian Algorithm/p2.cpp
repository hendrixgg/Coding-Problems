#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';

/*
returns the gcd(a, b) and at the same time, 
solves the linear combination: a*x + b*y = gcd(a, b)
*/
ll extgcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

// from problem j in: https://codeforces.com/gym/100963
/*
this problem can be framed as the following:

You have one ruler of length 'm' units and another ruler of length 'a' units.
Is it possible to exactly measure a length of 'c' units? 
If possible, What is the smallest number of rulers required to measure a length of 'c' units?

Where 'm' and 'a' are the units of time in the problem statement, n and k are given in the problem statement, and c = abs(k+a - n).

The answer will be: (the length of one of the rulers) + (the starting point of ruler).
*/
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n, m, a, k, xg, yg, x0, y0, g, c, shift;
    while(true)
    {
        cin >> n >> m >> a >> k;
        if(n == 0 && m == 0 && a == 0 && k == 0)
            return 0;
        // because the man can only reach for the first time at k + a
        k += a;
        // this ensures a situation where the man starts after the woman
        // and an equation of the form: y*m - x*a = k - n, where x, y, k, n > 0
        if(k < n)
        {
            swap(n, k), swap(m, a);
        }
        // check for solution to diophantine equation
        g = extgcd(a, m, xg, yg);
        // gives solution: a*xg + m*yg = gcd(a, m)
        c = k - n;
        if(c % g != 0)
        {
            cout << "Impossible\n";
            continue;
        }
        // now: a*x0 + m*y0 = c
        x0 = xg * c / g, y0 = yg * c / g;
        
        // shift x0 so that |x0| is minimum and x0 < 0
        // equivalently, shifting y0 so that |y0| is minimum and y0 > 0
        if(x0 > 0)
        {
            shift = (x0 * g + m - 1) / m;
            x0 -= shift * m / g;
            y0 += shift * a / g;
        }
        else // x0 <= 0
        {
            shift = (-x0 * g) / m;
            x0 += shift * m / g;
            y0 -= shift * a / g;
        }
        assert(k - x0 * a == n + y0 * m);
        cout << n + y0 * m << nl;
    }
}