#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define PI 3.141592653589793238L
const char nl = '\n';

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, t;
    cin >> n >> t;
    vector<int> book(n);
    for(int& b : book)
        cin >> b;
    int ans = 0;
    for(int l = 0, r = 0, sum = book[0]; r < n; ++l, ++r)
    {
        // read more books if you have time
        while(r+1 < n && sum + book[r+1] <= t) 
        {
            sum += book[++r];
        }
        // if you have enough time to read all books in range [l, r], update answer
        if(sum <= t)
            ans = max(ans, r - l + 1);
        
        // go to the next book
        sum -= book[l];
        if(r+1 < n)
            sum += book[r+1];
    }
    cout << ans;
    return 0;
}