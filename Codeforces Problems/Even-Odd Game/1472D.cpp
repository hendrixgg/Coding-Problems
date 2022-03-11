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
#include <queue>
//#include <set>
//#include <stack>
//#include <unordered_map>
//#include <unordered_set>
//#include <complex>   // for complex numbers
//#include <cmath>     // for trig and other math functions, but not bin_exp
#include <cstring>    // for memset
#include <algorithm> // for sorting and other algos
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
#ifdef HENDRIX
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
}

std::random_device                  rand_dev;
std::mt19937                        generator(rand_dev());
int random(const int& range_from, const int& range_to)
{
    std::uniform_int_distribution<int>    distr(range_from, range_to);
    return distr(generator);
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
#define fastio           ios_base::sync_with_stdio(false);cin.tie(NULL);
const char nl = '\n';

// global variables
int n, turn;
ll a, b, x;
// global variables

void testCase()
{
    scanI(n);
    a = b = 0;
    priority_queue<int> q;
    REP(i,n){
        scanI(x), q.push(x);
    }
    turn = 0;
    while(!q.empty()){
        x = q.top(), q.pop();
        if ( turn&1 ){
            if ( x&1 ) b += x;
            else ; // nothing
        } else {
            if ( x&1 ) ; // nothing
            else a += x;
        }
        turn ^= 1;
    }
    if ( a == b )
        puts("Tie");
    else
        puts( a > b ? "Alice" : "Bob");
}

int main()
{
    fastio;
    #ifdef HENDRIX
    fileio();
    auto begin = std::chrono::steady_clock::now();
    #endif // HENDRIX

    int TTT;
    scanI(TTT);
    REP(tttt,TTT) testCase();

    #ifdef HENDRIX
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    cerr << "\033[32mTime Elasped: " << duration.count() << " ms\033[0m" << endl;
    #endif // HENDRIX
    return 0;
}
