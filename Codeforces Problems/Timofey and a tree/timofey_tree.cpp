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
#endif // ONLINE_JUDGE
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

typedef long long                ll;
typedef long double            ld;
typedef unsigned long long    ull;
#define F            first
#define S            second
#define endl         '\n'
#define FOR(a, b, c) for (int a = (b); a < (int)(c) + 1; ++a)
#define ROF(a, b, c) for (int a = (b); a > (int)(c) - 1; --a)
#define REP(a, n)    for (int a = 0; a < (int)(n); ++a)

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
const int MAXN = 100001;
int n, colour[MAXN], curr_col;
vector<vector<int>> tree(MAXN);
bool ok;
// global variables

void dfs(int at, int parent)
{
    ok &= (colour[at] == curr_col);
    for(int adj : tree[at]){
        if (adj != parent)
            dfs(adj, at);
    }
}

bool can(int at)
{
    int ans = true;
    for (int adj : tree[at]){
        curr_col = colour[adj];
        ok = true;
        dfs(adj,at);
        ans &= ok;
    }
    return ans;
}

/** https://codeforces.com/problemset/problem/763/A */
/**
solution: find two adjacent nodes with different colours.

case 1: there are none
    -   print YES 1 since all nodes are the same colour

case 2: found two nodes with different colours, let them be root1 and root2
    observations: at least one of these nodes must be the root. Otherwise,
                  they would both be in a subtree (since they are adjacent)
                  and that does not work.
    -   from each node adjacent to root1, check if all nodes below
        the chosen node are the same colour using dfs and operator &=

        if(the result is true)
            print YES (root1)
        else if (do the same for root2)
            print YES (root2)
        else // neither worked
            print NO
*/
int main()
{
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
    tree.resize(n+1);
    REP(i,n-1){
        int u, v;
        readI(u), readI(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    FOR(i,1,n) readI(colour[i]);
    debug() << imie(tree);

    // check if tree is all same color
    int root1 = -1, root2 = -1;
    FOR(i,1,n){
        for (int adj : tree[i]){
            if (colour[adj] != colour[i]){
                root1 = adj;
                root2 = i;
            }
        }
    }
    if (root1 == -1){
        printf("YES\n1");
        return 0;
    }
    // have to solve
    if (can(root1)) printf("YES\n%d", root1);
    else if (can(root2)) printf("YES\n%d", root2);
    else printf("NO");
    return 0;
}
