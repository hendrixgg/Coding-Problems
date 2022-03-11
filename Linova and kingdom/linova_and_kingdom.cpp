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
#define ROF(a, b, c) for (int a = b; a > (c) - 1; --a)
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
template <typename T>
inline void readC(T &c){
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
const int MAXN = 200001;
vector<int> tree[MAXN];
int n, k;
int val_if_tour[MAXN];
ll answer = 0;
// global variables

int dfs(int at, int parent, int dist){
    val_if_tour[at] = tree[at].size() - dist++;
    for (int adj : tree[at]){
        if (adj == parent){
            val_if_tour[at] -= 1 + dist;
            continue;
        }
        val_if_tour[at] += dfs(adj, at, dist);
    }
    // adjust for subtracting distance above dfs's
    val_if_tour[at] += tree[at].size()*dist;
    return val_if_tour[at];
}

/**
the idea is to count the number of industry cities that visit a particular tourism city
rather than the number of tourism cities a particular industry city visits. This is simpler
because you do not have to keep track of the number of tourisim cities along a path but instead
just the number of industry cities in the subtree rooted at a tourism city.

it does not make sense to have a city which has developed tourisim to have a path which crosses an
industry city on the way to the capital. (parent city of tourism should always be tourism)
If you swapped the cities positions you would gain more happpiness. Since the farther away an industry
city is, the more tourism cities it can encounter. Tourism cities provide no increase to happiness
when not visited.

if a city develops industry with parents of tourism only, the benefit will be +(dist of city).
if a city develops tourism, the benefit will be (all cities that will visit)-(industry benefit)

Since k cities develop industry, n-k cities develop tourism. tourism cities provide happiness,
so count happiness gained by tourism cities.

Sort cities by their benefits of developing tourism and sum the highest n-k of them.
*/
int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    freopen("1.in","r",stdin);//freopen("1.out","r",stdout);
    readI(n), readI(k);
    REP(i,n-1)
    {
        int u, v;
        readI(u), readI(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    /*FOR(i,1,n)
    {
        cout << i << " -> ";
        for (int adj : tree[i])
            cout << adj << ", ";
        cout << endl;
    }*/

    dfs(1,0,0);
    // assigns the correct value to the n-th index in the range and puts all greater
    // values to the right of the n-th index and all lesser values to the left.
    nth_element(val_if_tour+1, val_if_tour+k, val_if_tour+n+1);
    //FOR(i,1,n) printf("%d, ", val_if_tour[i]);
    //printf("\n");
    FOR(i,k+1,n){
        answer += val_if_tour[i];
    }


    printf("%lld\n", answer);

    return 0;
}
