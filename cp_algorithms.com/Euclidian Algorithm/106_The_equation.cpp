#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
returns the gcd(a, b) and at the same time, 
solves the linear combination: a*x + b*y = gcd(a, b)
for integers x, y
*/
template<typename T>
T extgcd(T a, T b, T &x, T &y)
{
    x = 1, y = 0;
    T x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        T q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
template<typename T>
bool find_any_solution(T a, T b, T c, T &x0, T &y0, T &g) 
{
    g = extgcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
/*
returns the number of solutions to the equation a*x + b*y = c
for known integers a, b, c and unkown integers x, y.
for x:[minx, maxx], y:[miny, maxy]
*/
template<typename T>
T find_all_solutions(T a, T b, T c, T minx, T maxx, T miny, T maxy) 
{
    if(a == 0 && b == 0)
    {
        if(c == 0)
            return (maxx - minx + 1) * (maxy - miny + 1);
        else
            return 0;
    }
    if(a == 0)
    {
        if(c % b == 0 && miny <= c / b && c / b <= maxy)
            return maxx - minx + 1;
        else
            return 0;
    }
    if(b == 0)
    {
        if(c % a == 0 && minx <= c / a && c / a <= maxx)
           return maxy - miny + 1;
        else
            return 0;
    }
    T x, y, g;
    auto shift_solution = [&](T cnt) 
    {
        x += cnt * b;
        y -= cnt * a;
    };
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    T sign_a = a > 0 ? +1 : -1;
    T sign_b = b > 0 ? +1 : -1;

    shift_solution((minx - x) / b);
    if (x < minx)
        shift_solution(sign_b);
    if (x > maxx)
        return 0;
    T lx1 = x;

    shift_solution((maxx - x) / b);
    if (x > maxx)
        shift_solution(-sign_b);
    T rx1 = x;

    shift_solution(-(miny - y) / a);
    if (y < miny)
        shift_solution(-sign_a);
    if (y > maxy)
        return 0;
    T lx2 = x;

    shift_solution(-(maxy - y) / a);
    if (y > maxy)
        shift_solution(sign_a);
    T rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    T lx = max(lx1, lx2);
    T rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll a, b, c, x1, x2, y1, y2;
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;

    cout << find_all_solutions(a, b, -c, x1, x2, y1, y2) << '\n';
    return 0;
}