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
//#ifdef LOCAL
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
//#else
//sim dor(const c&) { ris; }
//#endif // LOCAL
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
#define FOR(a, b, c) for (int a = b; a < c + 1; ++a)
#define ROF(a, b, c) for (int a = b; a > c - 1; --a)
#define REP(a, n)    for (int a = 0; a < n; ++a)

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
template <typename T>
void readC(T &c){
    while((c=getchar())<' '|c>'~');
}

template <typename T>
void printgrid(T* grid, int rows, int cols)
{
    printf("\n");
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
            printf("%10d", (grid + r*cols)[c]);
        printf("\n");
    }
    cin.get();
}
// global variables
const int MAXN = 101, MOD = 1e9+7;
int n, k, d;
int dp[MAXN][2];
// global variables

int solve(int target, int who)
{
    if (dp[target][who] != -1)
        return dp[target][who];

    dp[target][who] = 0;
    if (who == 0) {
        FOR(i,1,k)
        {
            if (target-i < 0) break;
            dp[target][who] = (dp[target][who] + solve(target-i, who)) % MOD;
        }
    } else {
        FOR(i,1,d-1)
        {
            if (target-i < 0) break;
            dp[target][who] = (dp[target][who] + solve(target-i, who)) % MOD;
        }
    }
    return dp[target][who];
}

/**

*/
int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    //freopen("4.in","r",stdin);//freopen("1.out","r",stdout);
    readI(n), readI(k), readI(d);
    FOR(i,1,n) {dp[i][0] = dp[i][1] = -1;}
    dp[0][0] = dp[0][1] = 1;

    solve(n, 0); // all ways up to k
    solve(n, 1); // all ways up to d-1
    int ans = dp[n][0] - dp[n][1];
    if (ans < 0)
        ans += MOD;
    cout << ans << endl;

    return 0;
}
