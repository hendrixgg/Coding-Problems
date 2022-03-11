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

/**
going to take the biggest value from the gcd set,
that will be an element in the original array, will call this "big".

Remove the big element from the set.

Then will remove each occurrence of gcd(big, print[i]) from the set
twice since there will be gdc(big, actual[i]) and gcd(actual[i], big)
in the set.

https://codeforces.com/contest/583/problem/C
*/
int main()
{
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    //freopen("1.in","r",stdin);//freopen("1.out","r",stdout);
    int n;
    readI(n);
    int actual[n];
    multiset<int> gcds;
    REP(i,n*n)
    {
        int x;
        readI(x);
        gcds.insert(x);
    }
    REP(i,n)
    {
        int big = *gcds.rbegin(); // greatest element in acutal array
        gcds.erase(gcds.find(big)); // gcd(big,big)
        REP(j,i)
        {   // must be done twice since there will always be 2 ocurrences
            int tmp = __gcd(actual[j], big);
            gcds.erase(gcds.find(tmp));
            gcds.erase(gcds.find(tmp));
        }
        actual[i] = big;
        printf("%d ", big);
    }
    puts(""); // same as newline character

    return 0;
}
