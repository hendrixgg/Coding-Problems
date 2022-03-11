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
#define FOR(a, b, c) for (int a = (b); a < (c) + 1; ++a)
#define ROF(a, b, c) for (int a = (b); a > (c) - 1; --a)
#define REP(a, n)    for (int a = 0; a < (n); ++a)
const char nl = '\n';

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
const int MAXN = 201;
int n, ans = 0;
unordered_map<string, int> chain;
// global variables

int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    //freopen("1.in","r",stdin);//freopen("1.out","r",stdout);
    cin >> n;
    REP(i,n){
        string name1, r, name2;
        cin >> name1 >> r >> name2;
        // put to lower case
        REP(j, name1.size()) name1[j] += 32*(name1[j] < 97);
        REP(j,name2.size()) name2[j] += 32*(name2[j] < 97);
        if (chain.count(name2) == 0)
            chain[name1] = 2;
        else
            chain[name1] = 1 + chain[name2];
        //cerr << name1 << " " << chain[name1] << nl;
        ans = max(ans, chain[name1]);
    }
    cout << ans << nl;
    return 0;
}
