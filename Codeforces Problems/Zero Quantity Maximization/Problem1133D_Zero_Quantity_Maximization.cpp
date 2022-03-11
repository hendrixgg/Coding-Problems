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
    res *= 1 - 2*(l=='-'); // negative
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
const int MAXN = 200000;
int a[MAXN], b[MAXN], N;
map<pair<int, int>, int> freq;
// global variables

int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    //freopen("1.in","r",stdin);//freopen("1.out","r",stdout);
    readI(N);
    REP(i,N) readI(a[i]);REP(i,N) readI(b[i]);
    int zeros = 0;
    REP(i,N)
    {
        if (a[i] == 0)
        {
            if (b[i] == 0)
                ++zeros;
            continue;
        }
        int gcd = __gcd(abs(a[i]), abs(b[i]));
        a[i] /= gcd; b[i] /= gcd;
        if (a[i] < 0)
        {
            a[i] *= -1;
            b[i] *= -1;
        }
        ++freq[{-b[i], a[i]}];
    }
    int most_freq = 0;
    for (pair<pair<int,int>,int> f : freq)
        most_freq = max(most_freq, f.se);


    printf("%d\n", most_freq+zeros);
    return 0;
}
