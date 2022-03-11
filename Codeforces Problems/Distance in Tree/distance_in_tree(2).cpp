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

int n, k;

vector<vector<int>> G;
vector<int> v[1 << 16];

ll res = 0;

void dfs(int x, int p = -1)
{
	for(int to : G[x]){
		if (to == p)continue;
		dfs(to, x);
		if (v[to].size() > v[x].size())
			swap(v[to], v[x]);
		REP(j,v[to].size())
		{
			int d = v[to].size() - j - 1;
			if (0 <= k - d - 2 && k - d - 2 < (int)v[x].size())
				res += (ll)v[to][j] * v[x][v[x].size() - 1 - (k - d - 2)];
		}
		REP(j,v[to].size())
			v[x][v[x].size() - v[to].size() + j] += v[to][j];
	}
	v[x].push_back(1);
	if (k < (int)v[x].size())
		res += v[x][v[x].size() - 1 - k];
}

int main()
{
    #ifndef ONLINE_JUDGE
    INPUT_FILE;
    #endif // ONLINE_JUDGE
	scanf("%d%d", &n, &k);
	G.resize(n);
	for(int i = 0; i < n - 1; ++i)
	{
		int from, to;
		scanf("%d%d", &from, &to);
		--from, --to;
		G[from].push_back(to);
		G[to].push_back(from);
	}
	dfs(0);
	printf("%I64lli\n", res);
	return 0;
}
