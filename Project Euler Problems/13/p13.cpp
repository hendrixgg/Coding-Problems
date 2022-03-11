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

struct big_int {
    vector<int> num;
    const int base = 1000*1000*1000;

    big_int(){}

    big_int(const string& s)
    {
        for (int i = int(s.length()); i > 0; i -= 9)
            if (i < 9)
                num.push_back(atoi(s.substr(0, i).c_str()));
            else
                num.push_back(atoi(s.substr(i - 9, 9).c_str()));
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
    }

    big_int(char *s)
    {
        for (int i = int(strlen(s)); i > 0; i -= 9)
        {
            s[i] = 0;
            num.push_back(atoi(i >= 9 ? s + i - 9 : s));
        }
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
    }

    // increment 'this' by 'b', returns the result stored in *this
    big_int add(const big_int& b)
    {
        int carry = 0;
        for (size_t i = 0; i < max(num.size(), b.num.size()) || carry; ++i)
        {
            if (i == num.size())
                num.push_back(0);
            num[i] += carry + (i < b.num.size() ? b.num[i] : 0);
            carry = num[i] >= base;
            if (carry)
                num[i] -= base;
        }
        return *this;
    }

    // decrement 'this' by 'b', this >= b, returns the result stored in *this
    big_int sub(const big_int& b)
    {
        int carry = 0;
        for (size_t i = 0; i < b.num.size() || carry; ++i)
        {
            num[i] -= carry + (i < b.num.size() ? b.num[i] : 0);
            carry = num[i] < 0;
            if (carry)
                num[i] += base;
        }
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
        return *this;
    }

    // multiply this by b, returns the result stored in *this
    big_int mult(const big_int& b)
    {
        big_int a = *this;
        num.assign(a.num.size() + b.num.size(), 0);
        for (size_t i = 0; i < a.num.size(); ++i)
            for (int j = 0, carry = 0; j < (int)b.num.size() || carry; ++j)
            {
                long long cur = num[i + j] + a.num[i] * 1ll * (j < (int)b.num.size() ? b.num[j] : 0) + carry;
                num[i + j] = int(cur % base);
                carry = int(cur / base);
            }
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
        return *this;
    }

    void print()
    {
        printf("%d", num.empty() ? 0 : num.back());
        for (int i = int(num.size()) - 2; i >= 0; --i)
            printf("%09d", num[i]);
    }

};
// 5537376230390876637302048746832985971773659831892672
int main()
{
    char s[51];
    big_int a;
    for(int numbers = 100; numbers > 0; --numbers)
    {
        cin >> s;
        a.add(big_int(s));
    }
    a.print();
    return 0;
}