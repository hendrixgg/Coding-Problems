#include <bits/stdc++.h>
using namespace std;

//debug
#define LOCAL l
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
#ifdef LOCAL
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
#endif // LOCAL
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

typedef long long       ll;
typedef long double     ld;
#define F            first
#define S            second
#define ll           long long
#define ull          unsigned long long
#define endl         '\n'
#define FOR(a, b, c) for (int a = (b); a < (c) + 1; ++a)
#define ROF(a, b, c) for (int a = (b); a > (c) - 1; --a)
#define REP(a, n)    for (int a = 0; a < (n); ++a)

// reads a number
template <typename T>
inline void readI(T &res){
    char c, l=0;
    res=0;
    while((c=getchar())<'0'|c>'9')l=c;
    while(c>='0'&&c<='9'){
        res=res*10+(c-'0');
        c=getchar();
    }
    if (l=='-') // negative
        res *= -1;
}
inline void readC(char &c){
    while((c=getchar())<' '|c>'~');
}

template <typename T>
void printgrid(T grid, int rows, int cols)
{
    printf("\n");
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
            printf("%4d", (grid + r*cols)[c]);
        printf("\n");
    }
}
// global variables
const int MAXN = 200007;
int n, k;
vector<pair<int, int>> ranges[MAXN];
vector<ll> dp;
// global variables


/**
https://codeforces.com/problemset/problem/1216/F

Need segment tree to solve since this runs in O(N^2) and gives TLE.
*/
int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    //freopen("1.in","r",stdin);//freopen("1.out","r",stdout);
    readI(n), readI(k);
    dp.resize(n+1);
    REP(i,n)
    {
        char c;
        readC(c);
        if (c == '1')
        {
            int L = max(0,i-k);
            int R = min(n-1,i+k);
            ranges[R].emplace_back(L, i+1);
        }
    }

    //segment tree
    ll tree[2*n]; REP(i,2*n) tree[i] = LONG_LONG_MAX;
    // build up from 0's
    for (int i = n; i > 0; i/=2)
        tree[i] = 0;
    REP(i,n)
    {
        ll curr = dp[i] + (i+1);
        for (pair<int, int> p : ranges[i])
        {
            ll L = p.first, cost = p.second;
            int low = n + L, high = n+i+1;
            curr = min({curr, cost+tree[low], cost+tree[high-1]});
            while (low < high){
                if (low & 1)
                    curr = min(curr, cost+tree[low++]);
                if (high & 1)
                    curr = min(curr, cost+tree[--high]);
                low /= 2, high /= 2;
            }
        }
        dp[i+1] = curr;
        // build up from dp[i+1]
        // n+i '+1' because from dp[i+1]
        for (int j = n+i+1; j > 0; j /=2){
            tree[j] = min(curr, tree[j]);
        }

    }
    debug() << imie(dp);
    printf("%lld", dp[n]);

    return 0;
}
