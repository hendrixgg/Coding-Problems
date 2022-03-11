#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define FOR(a, b, c) for (int a = b; a < c + 1; ++a)
#define ROF(a, b, c) for (int a = b; a > c - 1; --a)
#define REP(a, n)    for (int a = 0; a < n; ++a)
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

/**
idea is to take the initial sum of all values and
also take the sum of (all values rounded down).
then we can pick at most n non-ints to give +1.
and at least, we can increase (n - ints) to give +1.

https://codeforces.com/problemset/problem/351/A
*/
int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    //freopen("2.in","r",stdin);//freopen("1.out","r",stdout);
    int N, a[2001], floor_sum=0, int_cnt=0;
    double init_sum=0;
    readI(N);
    for (int i = 0; i < 2*N; ++ i)
    {
        double in;
        scanf("%lf", &in);
        init_sum += in;
        // if an integer
        if (in - llround(in) == 0)
        {
            ++int_cnt;
            floor_sum += llround(in);
        }
        else // not integer
        {
            floor_sum += llround(floor(in));
        }
    }

    int reals = 2*N - int_cnt;
    int leastIncr = max(0, N - int_cnt);
    int mostIncr  = min(N, reals); // can give +1 to at most n real values
    int low_sum   = floor_sum + leastIncr;
    int hi_sum    = floor_sum + mostIncr;
    double minDiff = 1e15;
    // take lower bound
    if (init_sum < low_sum)
    {
        minDiff = low_sum - init_sum;
    }
    // take upper bound
    else if (init_sum > hi_sum)
    {
        minDiff = init_sum - hi_sum;
    }
    // we can have optimal answer
    else
    {
        minDiff = min(init_sum - floor(init_sum), ceil(init_sum) - init_sum);
    }
    /*
    FOR(x,low_sum,hi_sum) // take minimum diff of all possible final sums
    {
        minDiff = min(minDiff, abs(x-init_sum));
    }*/
    printf("%.3f\n", minDiff);
    return 0;
}
