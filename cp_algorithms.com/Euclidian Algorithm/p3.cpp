#include <bits/stdc++.h>
using namespace std;

/*
returns the gcd(a, b) and at the same time, 
solves the linear combination: a*x + b*y = gcd(a, b)
for integers x, y.
*/
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

bool TestCase()
{
    int a, b, c, x, y;
    cin >> a >> b >> c;
    if(c % extgcd(a, b, x, y) == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TTT, i;
    for (cin >> TTT, i = 1; i <= TTT; ++i)
        cout << "Case " << i << ": " << (TestCase() ? "Yes\n" : "No\n");
    return 0;
}