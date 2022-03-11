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
~debug() { cerr << endl; }eni(!=) cerr << boolalpha << i; ris; }eni(==) ris << range(begin(i), end(i)); }sim, class b dor(pair < b, c > d) {ris << "(" << d.first << ", " << d.second << ")";}sim dor(rge<c> d) {*this << "[";for (auto it = d.b; it != d.e; ++it)*this << ", " + 2 * (it == d.b) << *it;ris << "]";}
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int& age : a)
        cin >> age;
    // gr[i] = {gr.#, sum of ages, {age1, age2, ...}}
    vector<pair<pair<int, ll>, vector<int>>> gr;
    for(int i = 0; i < m; ++i)
    {
        int k; cin >> k;
        gr.push_back({{i, 0}, vector<int>(k)});
        for(int& age : gr[i].second)
        {
            cin >> age;
            gr[i].first.second += age;
        }
    }
    sort(a.begin(), a.end(), greater<int>());
    // sort in order of decreasing average age
    // but instead of dividing by size of groups, multiplying by common denominator 
    // x/x.size() > x/x.size() -> x*y.size() > y*x.size()
    sort(gr.begin(), gr.end(), [](const auto& x, const auto& y)
    {
        return x.first.second * y.second.size() > y.first.second * x.second.size();
    });
    
    debug() << imie(gr);
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