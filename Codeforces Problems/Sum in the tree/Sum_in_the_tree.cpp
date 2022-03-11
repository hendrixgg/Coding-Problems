#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define FOR(a, b, c) for (int a = b; a < c + 1; ++a)
#define ROF(a, b, c) for (int a = b; a > c-1; --a)
#define REP(a, n) for (int a = 0; a < n; ++a)
using namespace std;

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
int N, sums[MAXN], parent[MAXN], actualVal[MAXN];
ll sum;
vector<int> adjs[MAXN];
// global variables


bool BFS(int at, int numNodes)
{ // adjs must be a vector<vector<int>> or raw equivalent
    std::queue<int> nextNode;
    nextNode.push(at);
    while (!nextNode.empty())
    {
        int node = nextNode.front();
        nextNode.pop();
        if (sums[node] != -1) // already know what the sum is
        {
            for (int child : adjs[node])
                nextNode.push(child);
            actualVal[node] = sums[node] - sums[parent[node]];
        }
        else // we need to determine the sum
        {
            int sum_from_parent = sums[parent[node]];
            int min_sum_from_child = (int)1e9 + 5;
            for (int child : adjs[node])
            {
                nextNode.push(child);
                min_sum_from_child = min(min_sum_from_child, sums[child]);
            }
            if (min_sum_from_child < sum_from_parent)
            {
                printf("-1\n");
                return false;
            }
            if (min_sum_from_child == (int)1e9 + 5) // leaf node
            {
                actualVal[node] = 0;
                sums[node] = sum_from_parent;
                continue;
            }
            actualVal[node] = min_sum_from_child - sum_from_parent;
            sums[node] = min_sum_from_child;
        }
    }
    return true;
}

/**
https://codeforces.com/problemset/problem/1098/A
*/

int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    freopen("3.in","r",stdin);//freopen("1.out","r",stdout);
    readI(N);
    memset(actualVal, 0, sizeof(actualVal));
    REP(i,N-1)
    {
        int x;
        readI(x);
        adjs[x].pb(i+2);
        parent[i+2] = x;
    }
    FOR(i,1,N)
    {
        int x;
        readI(x);
        sums[i] = x;
    }

    parent[1] = 0;
    sums[0] = 0;

    FOR(i,1,0)
    {
        printf("%d -> ", i);
        for (int adj : adjs[i])
            printf("%d, ", adj);
        printf("p = %d \n", parent[i]);
    }

    bool get_sum = BFS(1, N);
    if (!get_sum) return 0;


    sum = 0;
    FOR(i,1,N)
    {
        sum += actualVal[i];
    }
    printf("%lld", sum);
    return 0;
}
