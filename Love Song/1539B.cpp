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
int n, q;
// global variables


int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    #ifndef ONLINE_JUDGE
    INPUT_FILE;
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &q);
    vector<int> song(n+1, 0);
    getchar();
    FOR(i,1,n)
    {
        song[i] = getchar() + song[i-1] - 'a' + 1;
    }
    //debug() << imie(song);
    while(q--){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", song[r] - song[l-1]);
    }
    return 0;
}
