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
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using ll = long long;
using ld = long double;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define PI 3.141592653589793238L
const char nl = '\n';

/* global variables */

/* global variables */

/*
We choose 10 cards at random from a standard deck of 52 cards. Find the EV of the number of aces.

same as asking: What is the expected # of aces you would find in the first 10 cards in the deck?

ev(# of aces pulled after pulling one card out of a standard deck) = 1/13

Now using the linearity of the expected value:
ev(# of aces pulled after pulling 10 cards out of a standard deck) = ev(# of aces pulled after pulling one card out of a standard deck) 
                                                                    + (# of aces pulled after pulling one card out of a standard deck) 
                                                                    + (# of aces pulled after pulling one card out of a standard deck)
                                                                ... + (# of aces pulled after pulling one card out of a standard deck)
Therefore:
ev(# of aces pulled after pulling 10 cards out of a standard deck) = 10*ev(# of aces pulled after pulling one card out of a standard deck)
*/
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<double> p(5); // p[i] = p-bility of pulling i aces so far
    p[0] = 1.0; // guaranteed to have pulled 0 aces after 0 pulls
    int total_card_pulls = 10, max_aces = 4;
    for(int i = 1; i <= total_card_pulls; ++i)
    {
        for(int ace = min(max_aces, i); ace >= 0; --ace)
        {
            double p_ace_right_now = (double)(4 - ace) / (52 - (i - 1));
            double p_ace_before = (double)(4 - (ace - 1)) / (52 - (i - 1));
            p[ace] = (ace != 0 ? p[ace - 1] * p_ace_before : 0) + p[ace] * (1 - p_ace_right_now);
        }
    }
    double ev = 0;
    for(int i = 0; i < 5; ++i)
    {
        ev += i*p[i];
    }
    debug() << imie(p);
    cout << "expected value: " << ev << " which is equal to: 10/13 = " << 10.0/13.0 << nl;
    return 0;
}