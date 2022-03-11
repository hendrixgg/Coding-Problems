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

template <class T>
bool palindrome(T &v)
{
    return std::equal(v.begin(), v.end(), v.rbegin());
}

/* global variables */

/* global variables */

template <typename T>
T bin_exp(T base, long long exp)
{
  T result = 1;
  while (exp > 0)
  {
    result *= ((exp & 1) == 1) * base + ((exp & 1) == 0); // if (exp % 2 == 1) result *= base;
    base *= base;
    exp >>= 1; // exp /= 2;
  }
  return result;
}

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n = 20;
    int total_required_powers[n+1]{};
    for(int i = n; i > 1; --i)
    {
        for(int d = 2, v = i, required_powers[n+1]{}; v > 1; ++d)
        {
            while(v % d == 0)
            {
                v /= d;
                ++required_powers[d];
            }
            total_required_powers[d] = max(total_required_powers[d], required_powers[d]);
        }
    }
    ll ans = 1;
    for(ll i = 1; i <= n; ++i)
    {
        // cout << i << ": " << total_required_powers[i] << nl;
        ans *= bin_exp(i, total_required_powers[i]);
    }
    cout << ans << nl;
    return 0;
}