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

#define INPUT_FILE  char f;                                     \
                    readC(f);                                   \
                    char IN[5] = {f, '.','i','n',0};            \
                    if (f == '-'){ /* need to write to file */  \
                        readC(f);                               \
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

inline void readC(char &c){
    while((c=getchar())<' '|c>'~');
}

// global variables
// global variables

void testCase()
{
    int n, cnt_good = 0;
    scanf("%d", &n);
    int arr[n];
    REP(i,n)
    {
        scanf("%d", &arr[i]);
    }
    cnt_good = n + n - 1; // for all subarrays of length 1 and 2
    for(int l = 0; l < n-2; ++l){
        // length 3 [l, l+1, l+2]
        if (arr[l] <= arr[l+1] && arr[l+1] <= arr[l+2])
            continue;
        if (arr[l] >= arr[l+1] && arr[l+1] >= arr[l+2])
            continue;
        ++cnt_good;
        if (l == n-3) break;
        // length 4 [l, l+1, l+2, l+3]
        if (arr[l+1] <= arr[l+2] && arr[l+2] <= arr[l+3]) // 2,3,4 up
            continue;
        if (arr[l+1] >= arr[l+2] && arr[l+2] >= arr[l+3]) // 2,3,4 down
            continue;
        if (arr[l] <= arr[l+1] && arr[l+1] <= arr[l+3]) // 1,2,4 up
            continue;
        if (arr[l] >= arr[l+1] && arr[l+1] >= arr[l+3]) // 1,2,4 down
            continue;
        if (arr[l] <= arr[l+2] && arr[l+2] <= arr[l+3]) // 1,3,4 up
            continue;
        if (arr[l] >= arr[l+2] && arr[l+2] >= arr[l+3]) // 1,3,4 down
            continue;
        ++cnt_good;
    }

    printf("%d \n", cnt_good);
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
