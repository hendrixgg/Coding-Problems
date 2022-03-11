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

const int MaxN = 100005;
struct Node
{
	int key, cnt, size, ls, rs, fa;
}	tree[MaxN*20];
struct Node2
{
	int tail, ls, next;
}	tr[MaxN];

int n, m, k, size1[MaxN], Q[10000000], ans, e[MaxN*2], next1[MaxN*2], lis[MaxN], cost[MaxN], dist[MaxN], tot;
int root[MaxN], l, fa[MaxN];
bool mark[MaxN];

inline void Renew(int x)
{
	tree[x].size = tree[tree[x].ls].size + tree[tree[x].rs].size + tree[x].cnt;
}
inline void Zig(int x)
{
	int y = tree[x].fa, z = tree[y].fa;
	tree[y].ls = tree[x].rs, tree[tree[x].rs].fa = y;
	tree[x].fa = z;
	if (tree[z].ls == y) tree[z].ls = x;
	else tree[z].rs = x;
	tree[y].fa = x, tree[x].rs = y;
	Renew(y);
}

inline void Zag(int x)
{
	int y = tree[x].fa, z = tree[y].fa;
	tree[y].rs = tree[x].ls, tree[tree[x].ls].fa = y;
	tree[x].fa = z;
	if (tree[z].ls == y) tree[z].ls = x;
	else tree[z].rs = x;
	tree[y].fa = x, tree[x].ls = y;
	Renew(y);
}

inline void Splay(int x, int &root)
{
	for (; tree[x].fa != 0; )
	{
		int y = tree[x].fa, z = tree[y].fa;
		if (z == 0){
			if (tree[y].ls == x) Zig(x);
			else Zag(x);
		}
		else{
			if (tree[z].ls == y){
				if (tree[y].ls == x) Zig(y), Zig(x);
				else Zag(x), Zig(x);
			}
			else{
				if (tree[y].rs == x) Zag(y), Zag(x);
				else Zig(x), Zag(x);
			}
		}
	}
	root = x;
	Renew(x);
}

inline void Find(int &root, int x)
{
	int p = root;
	for (; ; ){
		if (x == tree[p].key) break;
		if (x>tree[p].key)
			if (tree[p].rs != 0) p = tree[p].rs;
			else break;
		else
			if (tree[p].ls != 0) p = tree[p].ls;
			else break;
	}
	Splay(p, root);
	if (tree[p].key == x)
		ans += tree[p].cnt;
}

inline void Insert(int x, int &root)
{
	int p = root;
	for (; ; ){
		if (x == tree[p].key) break;
		if (x>tree[p].key)
			if (tree[p].rs != 0) p = tree[p].rs;
			else {tree[p].rs = tot + 1; break; }
		else
			if (tree[p].ls != 0) p = tree[p].ls;
			else {tree[p].ls = tot + 1; break; }
	}
	if (tree[p].key == x) tree[p].cnt ++ , Splay(p, root);
	else{
		tot ++ ;
		tree[tot].cnt = 1;
		tree[tot].key = x;
		tree[tot].fa = p;
		Splay(tot, root);
	}
}

void Dfs(int u)
{
	mark[u] = true;
	for (int v = tr[u].ls; v != 0; v = tr[v].next)
		Dfs(v);
	int max = 0, maxv = -1;
	for (int v = tr[u].ls; v != 0; v = tr[v].next)
	if (size1[v]>max) max = size1[v], maxv = v;
	if (maxv != -1){
		for (int v = tr[u].ls; v != 0; v = tr[v].next)
		if (v != maxv){
			int head = 0, tail = 1; Q[1] = v;
			while (head<tail)
			{
				head ++ ;
				for (int i = tr[Q[head]].ls; i != 0; i = tr[i].next)
					Q[ ++ tail] = i;
			}
			for (int i = 1; i <= tail; i ++ )
				Find(root[maxv], k + 2*dist[u]-dist[Q[i]]);
			for (int i = 1; i <= tail; i ++ )
				Insert(dist[Q[i]], root[maxv]);
		}
		Find(root[maxv], k + 2*dist[u]-dist[u]);
		Insert(dist[u], root[maxv]);
		root[u] = root[maxv];
		}
	else
	{
		root[u] =  ++ tot;
		tree[tot].key = dist[u];
		tree[tot].cnt = 1;
		tree[tot].size = 1;
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    INPUT_FILE;
    #endif // ONLINE_JUDGE
	scanf("%d%d", &n, &k);
	int x, y;
	for (int i = 1; i<n; i ++ )
	{
		scanf("%d%d", &x, &y);
		e[ ++ l] = y, next1[l] = lis[x], lis[x] = l; cost[l] = 1;
		e[ ++ l] = x; next1[l] = lis[y], lis[y] = l; cost[l] = 1;
	}
	int u, v, head = 0, tail = 1; Q[1] = 1; mark[1] = true; dist[1] = 0;
	while (head<tail)
	{
		u = Q[ ++ head];
		for (int i = lis[u]; i != 0; i = next1[i])
		{
			v = e[i];
			if (!mark[v])
			{
				if (!tr[u].ls) tr[u].ls = v;
				else tr[tr[u].tail].next = v;
				dist[v] = dist[u] + cost[i];
				tr[u].tail = v;
				Q[ ++ tail] = v;
				fa[v] = u;
				mark[v] = true;
			}
		}
	}
	for (int i = tail; i>0; i--)
		size1[Q[i]] ++ , size1[fa[Q[i]]] += size1[Q[i]];
	ans = 0; tot = 0;
	Dfs(1);
	printf("%d\n", ans);
	return 0;
}
