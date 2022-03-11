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
int answer = 0;
vector<int> spider[105];
// global variables

int dfs(int root, int parent)
{
    int max_depth = 0;
    for (int child : spider[root]){
        if (child == parent) continue;
        max_depth = max(max_depth, 1 + dfs(child, root));
    }
    return max_depth;
}

int main()
{
    //#ifndef ONLINE_JUDGE
    //INPUT_FILE;
    //#endif // ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d", &n);
    REP(i,n)
    {
        REP(c,105) spider[c].clear();
        int beads;
        scanf("%d", &beads);
        --beads;
        REP(c,beads)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            spider[a].push_back(b);
            spider[b].push_back(a);
        }
        int leaf = 1, max_length = 0;
        //dfs from every leaf node
        FOR(j,1,beads)
        {
            if (spider[j].size() == 1)
                max_length = max(max_length, dfs(j,-1));
        }
        answer += max_length;
    }
    printf("%d\n", answer);
    return 0;
}
