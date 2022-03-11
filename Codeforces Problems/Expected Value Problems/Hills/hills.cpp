#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define PI 3.141592653589793238L
const char nl = '\n';

/* global variables */

/* global variables */


/*
Given a sequence of length N (N ≤ 10^5), count triples of indices i < j < k that ai < aj > ak.

I implemented the solution with a segment tree to count the number of lesser elementsto the left and to the right of a given element.

Bonus: Count zig-zags of length 10, i.e. i1 < i2 < ... < i10 that a[i1] < a[i2] > a[i3] < a[i4] > ... < a[i10].
*/
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, pow2 = 1;
    cin >> n;
    while(pow2 < (n<<1)) 
    {
        pow2 <<= 1;
    }
    //   0 ,  1 , 2, 3
    // {max, min, l, r}
    vector<array<int, 4>> tree(pow2, {-INF, INF, -1, -1});
    // take input
    for (int i = n; i < (n<<1); ++i)
    {
        cin >> tree[i][0];
        tree[i][1] = tree[i][0];
        tree[i][2] = tree[i][3] = i - n;
    }
    // build the tree
    for(int i = n-1; i > 0; --i)
    {
        // max = max of two children
        tree[i][0] = max(tree[i<<1][0], tree[(i<<1)+1][0]);
        // min = min of two children
        tree[i][1] = min(tree[i<<1][1], tree[(i<<1)+1][1]);
        // l = left bound of left child
        tree[i][2] = tree[i<<1][2];
        // r = right bound of right child
        tree[i][3] = tree[(i<<1)+1][3];
    }

    function<int(int, int, int, int)> count_smaller = [&](int val, int l, int r, int pos)
    {
        // if out of bounds
        if(tree[pos][3] < l || r < tree[pos][2])
        {
            return 0;
        }
        // if min of range is not less than val
        if(tree[pos][1] >= val)
        {
            return 0;
        }
        // if range of qeuery is contained and maximum is less than val, return range
        if(l <= tree[pos][2] && tree[pos][3] <= r && tree[pos][0] < val)
        {
            return tree[pos][3] - tree[pos][2] + 1;
        }
        return count_smaller(val, l, r, pos<<1) + count_smaller(val, l, r, (pos<<1)+1);
    };
    
    ll ans = 0;
    for(int i = 1; i < n-1; ++i)
    {
        ans += count_smaller(tree[i+n][0], 0, i-1, 1) * count_smaller(tree[i+n][0], i+1, n-1, 1);
    }
    cout << ans << nl;
    return 0;
}