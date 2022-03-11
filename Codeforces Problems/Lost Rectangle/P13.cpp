#include <iostream>
#include <cstdio>
#include <cassert>
#include <random>
#include <chrono>
//#include <bitset>
//#include <utility>
//#include <tuple>
//#include <vector>
//#include <array>
//#include <map>
//#include <queue>
//#include <set>
//#include <stack>
//#include <unordered_map>
//#include <unordered_set>
//#include <complex>   // for complex numbers
//#include <cmath>     // for trig and other math functions, but not bin_exp
//#include <string>    // for memset
//#include <algorithm> // for sorting and other algos
//#include <numeric>
//#include <functional>// for passing funcitons as params into other functions
using namespace std;
#define getchar _getchar_nolock

//debug
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i)
sim > struct rge { c b, e;};
sim > rge<c> range(c i, c j) { return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
~debug() { cerr << endl; }
eni(!=){ cerr << boolalpha << i; ris; }
eni(==){ ris << range(begin(i), end(i)); }
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
#endif  // ONLINE_JUDGE
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

void fileio()
{
    #ifndef ONLINE_JUDGE
    char f = getchar();
    char IN[5] = {f, '.','i','n',0};
    if (f == '-') /* need to write to file */
        {
        f = getchar();
        IN[0] = f;
        FILE* tmp = fopen(IN,"w");
        /* write to file now */
        f = getchar();
        while(f != '`')
        {
            fprintf(tmp,"%c", f);
            f = getchar();
        }
        fclose(tmp);
    }
    freopen(IN,"r",stdin);
    #endif // ONLINE_JUDGE
}

// reads a number
template<typename T>
void scanI(T &num)
{
    char c, neg=0;
    num=0;
    while( (c=getchar()) < '0' || c > '9' )neg=c;
    while( c>='0'&&c<='9' )
    {
        num=num*10+(c-'0');
        c=getchar();
    }
    if (neg == '-')
        num *= -1;
}
template<typename t1, typename ... types>
void scanI(t1& num, types& ... nums)
{
    scanI(num);
    scanI(nums...);
}

template<typename T>
void outI(T n, const char after) //fast output
{
    bool neg = 0;

    if ( n < 0 )
        n *= -1, neg = 1;

    char snum[20];
    int i = 0;
    do
    {
        snum[i++] = n % 10 + '0';
        n /= 10;
    }while (n);

    if ( neg )
        putchar('-');

    while ( --i >= 0 )
        putchar(snum[i]);

    putchar(after);
}
template<typename T>
int float_digits(T& x, int div)
{
    int c = getchar();
    T pow10 = 1;
    bool neg = false;
    if (div && c == '\n')
        return 0;
    x = 0;
    while ( (c < '0' || c > '9') && c != '-' )
    {
        c = getchar();
    }
    if ( c == '-' )
    {
        neg = 1;
        c = getchar();
        if ( c == '0' || c == '.')
            return '-';
    }
    while ( !(c < '0' || c > '9') )
    {
        x *= 10;
        x += (c - '0');
        pow10 *= 10;
        c = getchar();
    }
    if ( neg )
        x = -x;
    if ( div )
        x /= pow10;
    return c;
}
// remember to compare speed to strtold
template<typename T>
void scanD(T& x) {
    double left, right = 0;
    int ret = float_digits(left, 0);
    if ( ret == '.' || ret == '-' )
    float_digits(right, 1);
    x = left + right;
    if (x < 0 )
        x -= 2*right;
    if ( ret == '-')
        x = -x;
}

template<typename t1, typename ... types>
void scanD(t1& num, types&...nums)
{
    scanD(num);
    scanD(nums...);
}

typedef long long                ll;
typedef long double            ld;
typedef unsigned long long    llu;
typedef unsigned int            uint;
#define F                first
#define S                second
#define PI 3.14159265358979323851280895940618620443274267017841339111328125
#define FOR(a, b, c)     for (int a = (b); a < (int)(c) + 1; ++a)
#define ROF(a, b, c)     for (int a = (b); a > (int)(c) - 1; --a)
#define REP(a, n)        for (int a = 0; a < (int)(n); ++a)
#define fastio           ios_base::sync_with_stdio(0);cin.tie(0);
const char nl = '\n';

// global variables
ll a, sq;
// global variables

//https://codeforces.com/group/yg7WhsFsAp/contest/355493/problem/P13
int main()
{
    fastio;
    #ifdef HENDRIX
    //fileio();
    #include <chrono>
    auto begin = std::chrono::steady_clock::now();
    #endif // HENDRIX
    scanI(a);
    if (a == 1)
    {
        outI(4, nl);
        return 0;
    }
    sq = (ll)ceil(sqrt(a));

    while (a % sq != 0){--sq;}

    outI(2*(sq + a/sq), nl);

    #ifdef HENDRIX
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    cerr << "[Time Elasped: " << duration.count() << " ms]" << endl;
    #endif // HENDRIX
    return 0;
}
