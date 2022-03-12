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
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

arithmetic series: https://www.cuemath.com/sum-of-arithmetic-sequence-formula/
*/

int main()
{
    // int limit = 1000, sum = 0;
    // for(int i = 1; 5*i < limit; ++i)
    //     sum += 3*i;

    // for(int i = 1; 5*i < limit; ++i)
    //     sum += 5*i;

    // for(int i = 1; 15*i < limit; ++i)
    //     sum -= 15*i;

    // cout << sum << nl;
    
    /*
    First of all, stop thinking on the number 1000 and turn your
    attention to the number 990 instead. If you solve the problem
    for 990 you just have to add 993, 995, 996 & 999 to it for
    the final answer. This sum is (a)=3983
    */
    int a = 3983;
    // sum of numbers divisible by 3 from 3... to 990 = 330/2 * (990 + 3)
    int b = 330 / 2 * (990 + 3);
    // sum of numbers divisible by 5 from 5... to 990 = 198 / 2 * (990 + 5)
    int c = 198 / 2 * (990 + 5);
    // sum of numbers divisible by (LCM(3,5) = 15) from 15... to 990 = 66 / 2 * (990 + 15)
    int d = 66 / 2 * (990 + 15);
    cout << a + b + c - d << nl;
    return 0;
}