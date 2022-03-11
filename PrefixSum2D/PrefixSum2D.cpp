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
#define REP(a, n) for (int a = 0; a < n; ++a)
using namespace std;

// reads a number
template <class T>
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

void readC(char &c){
    while((c=getchar())<' '|c>'~');
}

void printgrid(int* grid, int rows, int cols)
{
    printf("\n");
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
            printf("%4d", (grid + r*cols)[c]);
        printf("\n");
    }
    cin.get();
}

/*
Given a 2d array of N*M integers. Given Q qureies and in each query give r1, c1, r2, c2
print the sum of the elemnts in the square represented by (r1, c1) as the top left
corner and (r2, c2) as the bottom left corner.

Constraint:
1 <= N, M <= 10^3
1 <= a[i][j] <= 10^9
1 <= Q <= 10^5
1 <= r1 <= r2 <= N
1 <= c1 <= c2 <= M

test case
in:
3 3
3 6 2
8 9 2
3 4 1
2
1 1 2 2
1 2 3 3

out:
26
24
*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, Q, r1, c1, r2, c2;
    readI(N);
    readI(M);
    int arr[N+1][M+1], pre[N+1][M+1];
    REP(i,N+1)pre[i][0]=0;
    REP(i,M+1)pre[0][i]=0;
    FOR(i, 1, N)
    {
        FOR(j,1,M)
        {
            readI(arr[i][j]);
            pre[i][j] = arr[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    readI(Q);
    while(Q--)
    {
        readI(r1);
        readI(c1);
        readI(r2);
        readI(c2);
        // Naive approach
        // for (int i = r1; i <= r2; i++) {
        //     for (int j = c1; j < c2; j++) {
        //         sum += array[i][j];
        //     }
        // }
        cout << pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1] << "\n";
    }
    //printgrid((int*)pre, N+1, M+1);
    return 0;
}
