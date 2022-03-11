#include <iostream>
#include <cassert>
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

void fileio(){
    #ifndef ONLINE_JUDGE
    char f = getchar();
    char IN[5] = {f, '.','i','n',0};
    if (f == '-'){ /* need to write to file */
        f = getchar();
        IN[0] = f;
        FILE* tmp = fopen(IN,"w");
        /* write to file now */
        f = getchar();
        while(f != '`'){
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
void scanI(T &num){
    char c, neg=0;
    num=0;
    while( (c=getchar()) < '0' || c > '9' )neg=c;
    while( c>='0'&&c<='9' ){
        num=num*10+(c-'0');
        c=getchar();
    }
    if (neg == '-')
        num *= -1;
}
template<typename t1, typename ... types>
void scanI(t1& num, types& ... nums){
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
int float_digits(T x, bool div) {
  int c = getchar();
  T pow10 = 1;
  bool neg = false;
  x = 0;
  while ( (c < '0' || c > '9') && c != '-' ) {
    c = getchar();
  }
  if ( c == '-' ) {
    neg = 1;
    c = getchar();
  }
  while ( !(c < '0' || c > '9') ) {
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

template<typename T>
void scanD(T& x){
    T left, right = 0;
    bool neg = 0;
    int res = float_digits(left, 0);
    if (res = '.')
        float_digits(right, 1);
    x = left + right;
}
template<typename t1, typename ... types>
void scanD(t1& num, types& ... nums){
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
ll n, curr, best, ans, a[200000];
int check[200001], cnt;
// global variables

void testCase()
{
    ans = cnt = 0;
    scanI(n);
    assert(n>0);
    FOR(i,1,n) check[i] = n;
    check[0] = 0;

    scanI(a[0]);
    FOR(i,1,n-1){
        scanI(a[i]);
        if ((a[i] > 0)^(a[i-1] > 0)){
            check[++cnt] = i;
        }
    }

    FOR(c,0,cnt){
        best = LLONG_MIN;
        FOR(i,check[c], check[c+1]-1){
            best = max(best, a[i]);
        }
        ans += best;
    }
    outI(ans, nl);
}

int main()
{
    fastio; fileio();
    int TTT;
    scanI(TTT);
    REP(tttt,TTT) testCase();

    return 0;
}
