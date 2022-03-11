#include <bits/stdc++.h>
using namespace std;

/* global variables */

/* global variables */

int extgcd(int a, int b, int &x, int &y)
{
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
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

    int a, b, c, x, y, g, shift;
    cin >> a >> b >> c;
    g = extgcd(a, b, x, y);
    // no solution
    if(c % g != 0)
    {
        cout << "No\n";
        return 0;
    }
    // check for solution with positive x and y
    x *= c / g, y *= c / g;
    if(x < 0)
    {
        shift = (-x * g + b - 1) / b; // ceil(-x * g / b)
        x += shift * b / g;
        y -= shift * a / g;
    }
    else if(y < 0)
    {
        shift = (-y * g + a - 1) / a; // ceil(-y * g / a)
        x -= shift * b / g;
        y += shift * a / g;
    }
    if(x < 0 || y < 0)
    {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    return 0;
}