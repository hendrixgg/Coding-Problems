#include <bits/stdc++.h>
#define debug cerr<<"OK"
#define pii pair<int,int>
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
    char c, l;
    res=0;
    while((c=getchar())<'0'||c>'9')l=c;
    while(c>='0'&&c<='9'){
        res=res*10+(c-'0');
        c=getchar();
    }
    //if (l=='-') // negative
    //    res *= -1;
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
        printf("row %d: ", r);
        for (int c = 0; c < cols; ++c)
            printf("%10d", (grid + r*cols)[c]);
        printf("\n");
    }
}

// Variables
const int MAXN = 100000;
vector<int> adjs[MAXN];
ll MOD = 1000000007, dp[MAXN][3];
int colour[MAXN]; // 0, 1, or 2 for colour, -1 if not coloured
// Variables

void evaluate(int& node, int* eval)
{
    FOR(currCol,0,2)
    {
        if (colour[node] == -1)// colour not given
        {
            dp[node][currCol] = 1;
            continue;
        }
        if (colour[node] == currCol)
            dp[node][currCol] = 1; // colour given and same as current
        else
            dp[node][currCol] = 0; // colour given but not same as current
    }
    --eval[adjs[node][0]];
    node = adjs[node][0]; // now the parent node
    while (eval[node] == 0) // parent needs to be evaluated based on child nodes
    {
        int parent = 0;
        FOR(currCol,0,2)
        {
            int c1,c2;
            dp[node][currCol] = 0;
            if (currCol == 0)
                c1 = 1, c2 = 2;
            else if (currCol == 1)
                c1 = 0, c2 = 2;
            else // currCol == 2
                c1 = 0, c2 = 1;
            if (colour[node] == -1 || colour[node] == currCol)
            {
                dp[node][currCol] = 1;
                for (int child = adjs[node][0], i = 0; i < (int)adjs[node].size(); child = adjs[node][++i])
                {
                    if (eval[child] != 0){ parent = i; continue; } // do not modify the parent node
                    dp[node][currCol] *= dp[child][c1] + dp[child][c2];
                    if (dp[node][currCol] >= MOD)
                        dp[node][currCol] %= MOD;
                }
            }
        }
        if (node == 0) break;

        --eval[adjs[node][parent]];
        node = adjs[node][parent]; // new the parent node
    }
}

void DFS(int at, int numNodes)
{ // adjs must be a vector<vector<int>> or raw equivalent
    stack<int> nextNode;
    bool visited[numNodes];
    int eval[numNodes];
    FOR(i,0,numNodes-1){ visited[i] = false; eval[i] = 0; }
    nextNode.push(0);
    while (!nextNode.empty())
    {
        int node = nextNode.top();
        nextNode.pop();
        if (visited[node]) continue;
        visited[node] = true;
        // DFS pre-order eval
        for (int adj : adjs[node])
        {
            if (visited[adj]) continue;
            nextNode.push(adj);
            ++eval[node]; // how many adj nodes need to be evaluated until we can evaluate this node
        }
        // DFS post-order eval
        if (eval[node] == 0) evaluate(node, eval);
    }
}

int main()
{
    // there are only be 3 different colours
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("barnpainting.in","r",stdin);
    freopen("barnpainting.out","w",stdout);
    //freopen("8.in","r",stdin);
    //freopen("10.out","w",stdout);
    int n, k, x, y;
    readI(n), readI(k);
    FOR(i,0,n-1) colour[i]=-1;

    // edges
    REP(i,n-1)
    {
        readI(x), readI(y);
        adjs[x-1].push_back(y-1);
        adjs[y-1].push_back(x-1);
    }
    // colour nodes
    REP(i,k)
    {
        readI(x), readI(y); // node x-1 with colour y-1
        colour[x-1] = y-1;
    }

    //printgrid((ll*)dp,n,3);
    DFS(0, n);
    ll answer = (dp[0][0] + dp[0][1] + dp[0][2]) % MOD;

    cout << answer << "\n";
    return 0;
}
/**
if the node is a leaf - 2 cases:
    1. color already given:
        if currCol == giveCol: dp[node][currCol] = 1;
        else dp[node][currCol] = 0;
    2. colour not given:
        dp[node][currCol] = 1;

recursive cases:
    - need to solve all children before solving parent node
    - leaf nodes cannot have same colour as parent node

    cases:
        1. colour is given and not currCol: dp[node][currCol] = 0;
        2. currCol is valid [currCol==givenCol or there is no given colour]:
            multiply the options from all the children nodes
formula: for (int i = 0; i < node.children; ++i)
         {
             switch(currCol)
             {
                 case 1:
                    dp[node][currCol] *= dp[child_i][2] + dp[child_i][3];
                     break;
                 case 2:
                     dp[node][currCol] *= dp[child_i][1] + dp[child_i][3];
                     break;
                 case 3:
                     dp[node][currCol] *= dp[child_i][1] + dp[child_i][2];
                     break;
             }
         }
http://www.usaco.org/index.php?page=viewproblem2&cpid=766
*/
