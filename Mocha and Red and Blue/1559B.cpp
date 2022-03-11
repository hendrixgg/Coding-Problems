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

#define INPUT_FILE  char f = getchar();                         \
                    char IN[5] = {f, '.','i','n',0};            \
                    if (f == '-'){ /* need to write to file */  \
                        f = getchar();                          \
                        IN[0] = f;                              \
                        FILE* tmp = fopen(IN,"w");              \
                        /* write to file now */                 \
                        f = getchar();                          \
                        while(f != '`'){                        \
                            fprintf(tmp,"%c", f);               \
                            f = getchar();                      \
                        }                                       \
                        fclose(tmp);                            \
                    }                                           \
                    freopen(IN,"r",stdin);

typedef long long            ll;
typedef long double          ld;
typedef unsigned long long  ull;
#define F                first
#define S                second
#define FOR(a, b, c)     for (int a = (b); a < (int)(c) + 1; ++a)
#define ROF(a, b, c)     for (int a = (b); a > (int)(c) - 1; --a)
#define REP(a, n)        for (int a = 0; a < (int)(n); ++a)
const char nl = '\n';

// global variables
// global variables

void testCase()
{
    int n; scanf("%d", &n);
    char sq[n+2];
    scanf("%s", sq+1);
    int blanks = 0;
    FOR(i,1,n)
    {
        blanks += sq[i] == '?';
    }
    if (blanks == n){
        FOR(i,1,n) sq[i] = (i&1) ? 'B' : 'R';
        printf("%s\n", sq+1);
        return;
    }
    FOR(i,1,n)
    {
        if (sq[i] != '?'){
            char c[2] = {'B', 'R'};
            if (sq[i] == 'B'){
                c[0] = 'R';
                c[1] = 'B';
            }
            int j = i, x = 1;
            while(sq[--j] == '?'){
                sq[j] = c[(x^=1)];
            }
        }
    }
    ROF(i,n,1)
    {
        if (sq[i] != '?'){
            char c[2] = {'B', 'R'};
            if (sq[i] == 'B'){
                c[0] = 'R';
                c[1] = 'B';
            }
            int j = i, x = 1;
            while(sq[++j] == '?'){
                sq[j] = c[(x^=1)];
            }
        }
    }
    printf("%s\n", sq+1);
}

int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    #ifndef ONLINE_JUDGE
    INPUT_FILE;
    #endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    REP(t,T) testCase();

    return 0;
}
