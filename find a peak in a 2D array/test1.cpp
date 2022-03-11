#include <bits/stdc++.h>
using namespace std;

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

#define fastio      std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);

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

template<typename T>
T bin_exp(T base, long long exp){
    T result = 1;
    while (exp > 0){
        result *= ((exp&1) == 1)*base + ((exp&1) == 0); // if (exp % 2 == 1) result *= base;
        base *= base;
        exp >>= 1; // exp /= 2;
    }
    return result;
}

typedef long long            ll;    // scanf("%lld", &arg)
typedef long double          ld;    // scanf("%Lf", &arg)
typedef unsigned long long  llu;   // scanf("%llu", &arg); https://www.cplusplus.com/reference/cstdio/scanf/?kw=scanf
#define F                first
#define S                second
#define FOR(a, b, c)     for (int a = (b); a < (int)(c) + 1; ++a)
#define ROF(a, b, c)     for (int a = (b); a > (int)(c) - 1; --a)
#define REP(a, n)        for (int a = 0; a < (int)(n); ++a)
const char nl = '\n';

// global variables
int n, m, yl = 1, yr, xu = 1, xd, xm, ym;
int arr[10002][10002];
// global variables


int main()
{
    FOR(i,0,n+1) arr[i][0] = arr[i][m+1] = -1;
    FOR(i,0,m+1) arr[0][i] = arr[n+1][i] = -1;
    fastio; fileio();
    scanf("%d%d",&n, &m);
    xd = n;
    yr = m;
    FOR(i,1,n) FOR(j,1,m) scanf("%d", &arr[i][j]);
    // find a peak
    clock_t start_time = clock();
    bool bigx = false, bigy = false;
    while(!bigx || !bigy) {
        xm = (xd + xu) / 2;
        ym = (yr + yl) / 2;
        bigx = false, bigy = false;
        if (arr[xm][ym] < arr[xm][ym-1])
            yr = ym;
        else if (arr[xm][ym] < arr[xm][ym+1])
            yl = ym;
        else
            bigy = true;
        if (arr[xm][ym] < arr[xm-1][ym])
            xd = xm;
        else if (arr[xm][ym] < arr[xm+1][ym])
            xu = xm;
        else
            bigx = true;
    }
    printf("peak at: arr[%d][%d] = %d, time taken: %ld\n", xm, ym, arr[xm][ym], clock() - start_time);

    printf("   %3d   \n", arr[xm-1][ym]);
    printf("%3d   %3d\n", arr[xm][ym-1], arr[xm][ym+1]);
    printf("   %3d   \n", arr[xm+1][ym]);
    return 0;
}
