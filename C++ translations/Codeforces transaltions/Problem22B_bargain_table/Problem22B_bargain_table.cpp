#include <bits/stdc++.h>
#define debug cerr<<"OK"
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define FOR(a, b, c) for(int a = b; a < c+1; ++a)
#define REP(a, n) for(int a = 0; a < n; ++a)
using namespace std;

// reads a number
template <typename T>
inline void readI(T &res){
    char c, l;
    res=0;
    while((c=getchar())<'0'|c>'9')l=c;
    while(c>='0'&&c<='9'){
        res=res*10+(c-'0');
        c=getchar();
    }
    //if (l=='-') // negative
    //    res *= -1;
}
template<typename T>
void readC(T &c){
    while((c=getchar()-'0')!= 0 & c!= 1 );
}

void printgrid(int* grid, int rows, int cols)
{
    printf("\n");
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
            printf("%3d", (grid + r*cols)[c]);
        printf("\n");
    }
    cin.get();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    readI(N);
    readI(M);
    int grid[N+1][M+1], pre[N+1][M+1];
    REP(i,N+1)pre[i][0]=0;
    REP(j,M+1)pre[0][j]=0;
    FOR(i,1,N)
    {
        FOR(j,1,M)
        {
            readC(grid[i][j]);
            pre[i][j] = (grid[i][j] + pre[i-1][j]) + (pre[i][j-1] - pre[i-1][j-1]);
        }
    }
    // calculate max perimeter
    int max_p=0;
    FOR(r1,1,N)
    {
        FOR(c1,1,M)
        {
            if (grid[r1][c1] == 1) continue;
            FOR(r2,r1,N)
            {
                FOR(c2,c1,M)
                {
                    int ones = pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1];
                    if (ones==0) max_p = max(max_p, 2*(r2-r1+1) + 2*(c2-c1+1));
                }
            }
        }
    }
    cout << max_p;
    return 0;
}
