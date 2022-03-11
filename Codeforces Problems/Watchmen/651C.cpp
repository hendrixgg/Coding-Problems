#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;

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

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

// global variables
int n;
unordered_map<int, ll> freqx;
unordered_map<int, ll> freqy;
unordered_map<pair<int, int>, ll, pair_hash> points;
// global variables


int main()
{
    fileio();
    scanf("%d", &n);
    REP(i,n){
        int x, y;
        scanf("%d%d", &x, &y);
        if (points.count({x,y}) == 0){
            points.insert({{x,y}, 1});
        }else
            ++points[{x,y}];

        if (freqx.count(x) == 0){
            freqx.insert({x,1});
        } else{
            ++freqx[x];
        }

        if (freqy.count(y) == 0){
            freqy.insert({y, 1});
        } else{
            ++freqy[y];
        }
    }
    ll ans = 0;
    // points with same x-coords
    for (const pair<int, ll>& p : freqx)
        ans += p.S*(p.S-1);
    // points with same y-coords
    for (const pair<int, ll>& p : freqy)
        ans += p.S*(p.S-1);
    ans >>= 1; // ans /= 2;
    // points that coincide
    for (auto it = points.begin(); it != points.end(); ++it){
        ans -= ((it->S)*((it->S)-1))>>1;
    }
    printf("%lld\n", ans);
    return 0;
}
