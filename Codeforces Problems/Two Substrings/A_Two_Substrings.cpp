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

    string s;
    cin >> s;
    bool found_ab = false, found_ba = false;
    for(int l = 1, r = s.length()-2; l < r && (!found_ab || !found_ba);)
    {
        if (s[l-1] == 'A' && s[l] == 'B')
        {
            found_ab = true;
        }
        else
        {
            ++l;
        }
        if (s[r] == 'B' && s[r+1] == 'A')
        {
            found_ba = true;
        }
        else
        {
            --r;
        }
    }
    if(found_ab && found_ba)
    {
        cout << "YES";
        return 0;
    }
    found_ab = found_ba = false;
    for(int l = 1, r = s.length()-2; l < r && (!found_ab || !found_ba);)
    {
        if (s[l-1] == 'B' && s[l] == 'A')
        {
            found_ba = true;
        }
        else
        {
            ++l;
        }
        if (s[r] == 'A' && s[r+1] == 'B')
        {
            found_ab = true;
        }
        else
        {
            --r;
        }
    }
    if(found_ab && found_ba)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}