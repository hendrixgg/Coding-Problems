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

const uint64_t maxn = 1000*1000;
uint64_t dp[maxn];

uint64_t count_chain(uint64_t input)
{
    uint64_t cnt = 1;
    for(uint64_t n = input; n > 1; )
    {
        if(n&1)     
            n = 3*n + 1;
        else    
            n = n / 2;
        ++cnt;
    }
    return cnt;
}

/*
n → n/2 (n is even)
n → 3n + 1 (n is odd)

Which starting number, under one million, produces the longest chain?
*/
int main()
{
    cin.tie(0);
    dp[1] = 1;
    ios::sync_with_stdio(0);
    cerr << "[Program Start]" << nl;
    auto begin = std::chrono::steady_clock::now();
    
    uint64_t max_chain = 0, max_starting_number = 1, new_chain = 0;
    for(uint64_t n = 1; n < 1000*1000; ++n)
    {
        new_chain = count_chain(n);
        if(new_chain > max_chain)
        {
            max_chain = new_chain;
            max_starting_number = n;
        }
    }
    cout << max_starting_number << nl;
    
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    cerr << "[Time Elasped: " << duration.count() << " ms]" << nl;
    return 0;
}