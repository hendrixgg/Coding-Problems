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
    char c;
    res=0;
    while((c=getchar())<'0'|c>'9');
    while(c>='0'&&c<='9'){
        res=res*10+(c-'0');
        c=getchar();
    }
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

int main()
{
    int n, t;
    readI(n);
    readI(t);
    char q[n];
    bool swapPrev[n-1];
    REP(i, n)readC(q[i]);

    REP(s, t)
    {
        REP(i, n-1)
            swapPrev[i] = (q[i] == 'B' && q[i+1] == 'G');
        REP(i, n-1)
        {
            if (swapPrev[i])
            {
                q[i] = 'G';
                q[i+1] = 'B';
            }
        }
    }
    REP(i, n)printf("%c", q[i]);
    return 0;
}
