#include <iostream>
#include <bitset>
//#include <vector>
#include <array>
//#include <map>
//#include <queue>
//#include <set>
//#include <stack>
//#include <unordered_map>
//#include <unordered_set>
//#include <complex>   // for complex numbers
//#include <cmath>     // for trig and other math functions, but not bin_exp
//#include <string>    // for memset
//#include <algorithm> // for sorting and other algos
using namespace std;

void fileio(){
    #ifndef ONLINE_JUDGE
    char f = getchar();
    char IN[5] = {f, '.','i','n',0};
    if (f == '-'){ /* need to write to file */
        f = getchar();
        IN[0] = f;
        FILE* tmp = fopen(IN,"w");
        /* write to file now */
        f = getchar();
        while(f != '`'){
            fprintf(tmp,"%c", f);
            f = getchar();
        }
        fclose(tmp);
    }
    freopen(IN,"r",stdin);
    #endif // ONLINE_JUDGE
}

typedef long long            ll;    // scanf("%lld", &arg)
typedef long double          ld;    // scanf("%Lf", &arg)
typedef unsigned long long  llu;   // scanf("%llu", &arg); https://www.cplusplus.com/reference/cstdio/scanf/?kw=scanf
#define F                first
#define S                second
#define PI 3.14159265358979323851280895940618620443274267017841339111328125
#define FOR(a, b, c)     for (int a = (b); a < (int)(c) + 1; ++a)
#define ROF(a, b, c)     for (int a = (b); a > (int)(c) - 1; --a)
#define REP(a, n)        for (int a = 0; a < (int)(n); ++a)
const char nl = '\n';

// global variables
int q, d, TTT, a;
array<bitset<100>, 10> can;
// global variables

int main()
{
    fileio();
    FOR(d,1,9){ // for each digit
        can[d][0] = 1;
        FOR(j,0,99){ // for each number from 0-99
            if (j%10 == d || j/10 == d){ // if that number has d as a digit
                FOR(k,0,99-j){ // for all k, if k was an achievable number then k+j is also achievable
                    can[d][k+j] = can[d][k+j] || can[d][k];
                }
            }
        }
    }
    scanf("%d", &TTT);
    REP(tttt,TTT){
        scanf("%d%d", &q, &d);
        REP(i,q){
            scanf("%d", &a);
            if (a >= 100 || can[d][a])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
