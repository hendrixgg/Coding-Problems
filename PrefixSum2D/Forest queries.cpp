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
const int MAXN = 1001;
vector<vector<int>> prefix(MAXN);
// global variables

/*
Input:
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2

Output:
3
1
2
*/
int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    //freopen("1.in","r",stdin);//freopen("1.out","r",stdout);
    int n, q;
    readI(n), readI(q);
    prefix.resize(n+1);
    FOR(i,0,n) prefix[i].resize(n+1);
    FOR(i,1,n){
        FOR(j,1,n){
            char c;
            readC(c);
            prefix[i][j] = (c=='*') + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    REP(i,q){
        int y1, x1, y2, x2;
        readI(y1), readI(x1), readI(y2), readI(x2);
        cout << prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1] << nl;
    }
    //debug() << imie(prefix);
    return 0;
}
