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
            printf("%4d", (grid + r*cols)[c]);
        printf("\n");
    }
}
// global variables
// global variables

void test_case()
{
    int n, zeros=0, c;
    readI(n);
    REP(i,n)
    {
        readC(c);
        zeros += c == '0';
    }
    /*  zeros == 1: alice will put a 1 and then the game is over so she loses
        zeros % 2 == 0:
        there will be 2*n + 1 turns ending on alice every time

        alice puts a 1 then bob flips, then alice puts 1 again so a = 2, b = 0.
        then this happens an even number of times after this so alice always ends with 2 more than bob
    */
    if (zeros == 1 || zeros % 2 == 0)
        printf("BOB\n");
    else
        printf("ALICE\n");

}

/**
Alice goes first
game never actually ends in a draw
https://codeforces.com/problemset/problem/1527/B1
*/
int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    //freopen("1.in","r",stdin);//freopen("1.out","r",stdout);
    int T;
    readI(T);
    REP(t,T) test_case();

    return 0;
}
