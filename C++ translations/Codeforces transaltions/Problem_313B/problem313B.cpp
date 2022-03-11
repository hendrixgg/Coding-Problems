#include <bits/stdc++.h>
#define debug cerr<<"OK";
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
            printf("%3d", (grid + r*cols)[c]);
        printf("\n");
    }
}
/** https://codeforces.com/contest/313/problem/B */
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, cnt=1, dp[100005], n;
    char l, c;
    readC(l);
    dp[0]=0; // initial
    while((c=getchar())=='.'|c=='#')
    {
        dp[cnt] = dp[cnt-1] + (l==c);
        l=c;
        ++cnt;
    }
    readI(n);
    REP(i, n)
    {
        readI(a);
        readI(b);
        cout << dp[b-1]-dp[a-1] << "\n";
    }
    return 0;
}
