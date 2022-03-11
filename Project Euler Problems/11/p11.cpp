#include <bits/stdc++.h>
using namespace std;
#define dbarrt(x, n) cerr << #x << ": " << '\n', _dbarrt((x), (n))
#define dbarr(x, n) cerr << #x << ": ", _dbarr((x), (n))
template <typename T>
void _dbarr(const T a, size_t sz)
{
    for (size_t i = 0; i < sz; ++i)
        cerr << a[i] << ' ';
    cerr << '\n';
}
template <typename T>
void _dbarrt(const T a, size_t sz)
{
    for (size_t i = 0; i < sz; ++i)
        cerr << a[i] << '\n';
    cerr << "i:" << '\n';
    for (size_t i = 0; i < sz; ++i)
        cerr << i << '\n';
}
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef CPH
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define HERE cerr << "Passing [" << __FUNCTION__ << "] in LINE " << __LINE__ << '\n'
#define imie(x) " [" << #x ": " << (x) << "] "
using ll = long long;
using ld = long double;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define PI 3.141592653589793238L
const char nl = '\n';

/* global variables */

/* global variables */


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    unsigned n = 20, max_val = 0;
    vector<vector<uint32_t>> a(n, vector<uint32_t>(20));
    for(vector<uint32_t>& row : a)
        for(uint32_t& ai : row)
            cin >> ai;
    
    // rows
    for(vector<uint32_t>& row : a)
    {   
        for(uint32_t col = 0; col + 3 < n; ++col)
        {
            max_val = max(max_val, row[col] * row[col+1] * row[col+2] * row[col+3]);
        }
    }
    // columns
    for(uint32_t col = 0; col < n; ++col)
    {
        for(uint32_t row = 0; row + 3 < n; ++row)
        {
            max_val = max(max_val, a[row][col] * a[row+1][col] * a[row+2][col] * a[row+3][col]);
        }
    }
    // diagonals down towards right
    for(uint32_t row = 0; row + 3 < n; ++row)
    {
        for(uint32_t col = 0; col + 3 < n; ++col)
        {
            max_val = max(max_val, a[row][col] * a[row+1][col+1] * a[row+2][col+2] * a[row+3][col+3]);
        }
    }
    // diagonals down towards left
    for(uint32_t row = 0; row + 3 < n; ++row)
    {
        for(uint32_t col = 3; col < n; ++col)
        {
            max_val = max(max_val, a[row][col] * a[row+1][col-1] * a[row+2][col-2] * a[row+3][col-3]);
        }
    }
    cout << max_val << nl;
    return 0;
}