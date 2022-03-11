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
            printf("%3d", (grid + r*cols)[c]);
        printf("\n");
    }
}

/**
6 3
1 3 5 2 5 4
1 1 0 1 0 0
https://codeforces.com/problemset/problem/961/B
*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, awake=0, maxt;
    bool tmp;
    readI(n), readI(k);
    int bonus[n+1] = {0};
    FOR(i,1,n)readI(bonus[i]);

    FOR(i,1,n)
    {
        readI(tmp);
        awake += (tmp) * bonus[i]; // for free
        bonus[i] = (!tmp) * bonus[i] + bonus[i-1];
    }
    maxt = awake;
    FOR(i,1,n-k+1)
        maxt = max(maxt, awake + bonus[i+k-1] - bonus[i-1]);

    cout << maxt;

    return 0;
}
