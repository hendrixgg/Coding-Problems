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

/*
0 0 0 0 X 0 0 X
0 0 0 0 0 0 2 0
0 0 0 0 0 2 0 0
0 0 0 0 X 0 0 X
X 0 0 X 2 0 2 2
0 0 2 0 1 6 2 1
0 2 0 0 2 4 7 4
X 0 0 X 2 0 1 6

at least one of the X's must be clear.
at most, one of the X's need be clear.
therefore, should clear the smallest X.
*/
ll grid[500][500];
void TestCase()
{
    int n;
    cin >> n;
    ll sum = 0, min_add = INF;
    // input
    for(int i = 0; i < n<<1; ++i)
        for(int j = 0; j < n<<1; ++j)
            cin >> grid[i][j];
    // sum of bottom right quadrant
    for(int i = n; i < n<<1; ++i)
        for(int j = n; j < n<<1; ++j)
            sum += grid[i][j];
    if(n == 1)
    {
        cout << sum + min(grid[0][1], grid[1][0]) << nl;
        return;
    }
    // check four corners in top right quadrant and bottom left quadrant
    for(int t = 0; t < 2; ++t)
        for(int i = 0; i < n; i += n-1)
            for(int j = n; j < n<<1; j += n-1)
                min_add = min(min_add, grid[(t == 0 ? i : j)][(t == 0 ? j : i)]);
    
    cout << sum  + min_add << nl;
}

int main()
{
    int TTT;
    for (cin >> TTT; TTT != 0; --TTT)
        TestCase();
    return 0;
}