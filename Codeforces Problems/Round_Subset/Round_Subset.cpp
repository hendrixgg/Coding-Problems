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
    while((c=getchar())<'0'|c>'9')l=c;
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
        for (int c = 0; c < cols; ++c)
            printf("%3d", (grid + r*cols)[c]);
        printf("\n");
    }
}
// Variables
const int MAXN = 200;
int pw5[MAXN], pw2[MAXN];
int dp[2][MAXN][MAXN*26]; // *26 since 10^18 has 25.smth factors of 5 // can do dp[2][MAXN][MAXN*26] if you switch pointers
int n, k;
// Variables

/**
dp[i][j][c5]= c2 where the product of j numbers, with i numbers considered and
c5 factors of 5 has c2 factors of 2;
*/


/** https://codeforces.com/problemset/problem/837/D */
/// tutorial: https://codeforces.com/blog/entry/53662
// https://codeforces.com/contest/837/submission/29514225
// https://codeforces.com/contest/837/submission/29441206
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //ifstream input("1.in");freopen("1.in","r",stdin);freopen("1.out","r",stdout);
    readI(n), readI(k);
    for (int i = 0; i<n; ++i)
    {
        ll x;
        readI(x), pw2[i] = 0, pw5[i] = 0;
        while (x % 2 == 0) ++pw2[i], in /= 2;
        while (x % 5 == 0) ++pw5[i], in /= 5;
    }




    return 0;
}
