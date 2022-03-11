#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int& ai : a)
    {
        cin >> ai;
    }
    sort(a.begin(), a.end());
    if(k == 0)
    {
        cout << (a[0] == 1 ? "-1\n" : "1\n");
    }
    else if(a[k-1] == a[k])
    {
        cout << "-1\n";
    }
    else
    {
        cout << a[k-1] << nl;
    }
    return 0;
}