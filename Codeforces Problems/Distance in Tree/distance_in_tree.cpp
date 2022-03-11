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
const int MAXN = 50001, MAXK = 501;
int n, k;
// d_all[rt][d] stores the number of nodes a distance d, from rt, d_all[rt][0]=1
//vector<vector<int>> d_all;
int d_all[MAXN][MAXK];
int64_t answer = 0;
vector<vector<int>> tree;
// global variables

void dfs(int rt, int parent)
{   // count the root itself
    d_all[rt][0] = 1;
    for (int adj : tree[rt]){
        if (adj == parent)continue;
        dfs(adj,rt);
        // pairs of verticies distance d away
        FOR(d,1,k)
            answer += d_all[adj][d-1] * d_all[rt][k-d];
        // count verticies in subtree
        // this is done after computing adding to
        // answer so we do not get duplicate pairs
        FOR(d,1,k)
            d_all[rt][d] += d_all[adj][d-1];
    }
}

/** https://codeforces.com/problemset/problem/161/D */
// lord and saviour: https://www.geeksforgeeks.org/find-the-number-of-distinct-pairs-of-vertices-which-have-a-distance-of-exactly-k-in-a-tree/
int main()
{
    #ifndef ONLINE_JUDGE
    INPUT_FILE;
    #endif // ONLINE_JUDGE
    scanf("%d%d", &n, &k);
    //d_all.resize(n+1);FOR(i,1,n)d_all[i].resize(k+1);
    tree.resize(n+1);
    REP(i,n-1){
        int a, b;
        scanf("%d%d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1,0);
    //debug() << imie(d_below);
    //debug() << imie(d_all);
    printf("%I64lli\n", answer);
    return 0;
}
