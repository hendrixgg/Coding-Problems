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

typedef long long            ll;
typedef long double          ld;
typedef unsigned long long  ull;
#define F                first
#define S                second
#define FOR(a, b, c)    for (int a = (b); a < (c) + 1; ++a)
#define ROF(a, b, c)    for (int a = (b); a > (c) - 1; --a)
#define REP(a, n)        for (int a = 0; a < (n); ++a)
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
    //if (l=='-') // negative
      //  res *= -1;
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
const int MAXN = 100001;
int n;
double ans;
vector<vector<int>> tree(MAXN);
// global variables

double compute(int at, int parent)
{
    double roads = tree[at].size() - (parent != 0);
    if (roads == 0) return 0; // if leaf node - avoid div by 0
    double adj_avg = 0;
    for (int adj : tree[at]){
        if (adj == parent) continue;
        adj_avg += 1 + compute(adj, at);
    }
    return adj_avg / roads;
}

int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        char f;
        readC(f);
        char IN[5] = {f, '.','i','n',0}, OUT[6] = {f,'.','o','u','t',0};
        if (f == '-'){ // need to write to file
            readC(f);
            IN[0] = f;OUT[0] = f;
            FILE* tmp = fopen(IN,"w");
            f = getchar();f = getchar();
            while(f != '`'){
                fprintf(tmp,"%c", f);
                f = getchar();
            }
            fclose(tmp);
        }
        freopen(IN,"r",stdin);//freopen(OUT,"w",stdout);
    #endif
    readI(n);
    tree.resize(n);
    REP(i,n-1){
        int u, v;
        readI(u), readI(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    debug() << imie(tree);
    printf("%.15lf\n", compute(1,0));
    return 0;
}
