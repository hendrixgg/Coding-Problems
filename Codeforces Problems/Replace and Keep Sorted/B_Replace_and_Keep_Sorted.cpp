#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, q, k;
    cin >> n >> q >> k;
    // all the elements are positive integers between 1 and k (inclusive)
    vector<int> a(n);
    for(int& ai : a)
        cin >> ai;
    if(n == 1)
    {
        --k;
        for(; q > 0; --q)
        {
            cout << k << nl;
        }
        return 0;
    }
    // posibilities[i] = number of different possible values a[i-1] can be while 'a' remains in strictly increasing order
    vector<int> possibilities(n+1);
    possibilities[1] = a[1]-a[0]-1 + a[0]-1;
    for(int i = 1; i+1 < n; ++i)
    {
        possibilities[i+1] = (a[i+1]-a[i]-1) + (a[i]-a[i-1]-1);
    }
    possibilities[n] = a[n-1]-a[n-2]-1 + k-a[n-1];
    // make into a prefix sum
    for(int i = 1; i <= n; ++i)
    {
        possibilities[i] += possibilities[i-1];
    }
    for(int l, r; q > 0; --q)
    {
        cin >> l >> r;
        int ans = possibilities[r] - possibilities[l-1];
        if(l > 1)
            ans += a[l-2];
        if(r < n)
            ans += k - a[r] + 1;
        cout << ans << nl;
    }
    return 0;
}