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
#define imie(x) " [" << #x ": " << (x) << "] "
#define HERE cerr << "Passing [" << __FUNCTION__ << "] in LINE " << __LINE__ << '\n'
using ll = long long;
using ld = long double;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define PI 3.141592653589793238L
const char nl = '\n';

/* global variables */

/* global variables */

void TestCase()
{
    HERE;
    ll n;
    cin >> n;
    int lo = INF, hi = -1, range = -INF;
    int lo_cost = INF, hi_cost = INF, range_cost = INF;
    for (ll i = 0, new_lo, new_hi, new_cost; i < n; ++i)
    {
        cin >> new_lo >> new_hi >> new_cost;
        if(new_lo < lo || (new_lo == lo && new_cost < lo_cost))
        {
            lo = new_lo;
            lo_cost = new_cost;
        }
        if(hi < new_hi || (new_hi == hi && new_cost < hi_cost))
        {
            hi = new_hi;
            hi_cost = new_cost;
        }
        if(new_hi - new_lo > range || (new_hi - new_lo == range && new_cost < range_cost))
        {
            range = new_hi - new_lo;
            range_cost = new_cost;
        }
        if(hi - lo > range)
        {
            cout << lo_cost + hi_cost << nl;
        }
        else
        {
            cout << min(lo_cost + hi_cost, range_cost) << nl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TTT;
    for (cin >> TTT; TTT != 0; --TTT)
        TestCase();
    return 0;
}