#include <iostream>
//#include <bitset>
//#include <utility>
//#include <tuple>
//#include <vector>
//#include <array>
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
//#include <numeric>
//#include <functional>// for passing funcitons as params into other functions
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

// reads a number
template<class T>
void scanI(T &num){
    char c, l;
    num=0;
    while(((c=getchar())<'0')||(c>'9'))l=c;
    while(c>='0'&&c<='9'){
        num=num*10+(c-'0');
        c=getchar();
    }
    num *= (l=='-')*-1 + (l!='-'); // for negatives
}
template<class t1, class ... types>
void scanI(t1& num, types& ... nums){
    scanI(num);
    scanI(nums...);
}

template<typename T> void outI(const char after, T& n) //fast output
{
	bool neg = 0;
    n *= (n < 0)*-1 + (n > -1), neg = n < 0;

	char snum[20];
	int i = 0;
	do
	{
		snum[i++] = n % 10 + '0';
		n /= 10;
	} while (n);

	if (neg)
		putchar('-');

	while (--i >= 0)
		putchar(snum[i]);

    putchar(after);
}
template<class t1, class ... types>
void outI(const char separator, t1& num, types& ... nums){
    outI(separator, num);
    outI(separator, nums...);
}
typedef long long            ll;
typedef long double          ld;
typedef unsigned long long  llu;
typedef unsigned int         uint;
#define F                first
#define S                second
#define PI 3.14159265358979323851280895940618620443274267017841339111328125
#define FOR(a, b, c)     for (int a = (b); a < (int)(c) + 1; ++a)
#define ROF(a, b, c)     for (int a = (b); a > (int)(c) - 1; --a)
#define REP(a, n)        for (int a = 0; a < (int)(n); ++a)
#define fastio      std::ios_base::sync_with_stdio(0);std::cin.tie(0);
const char nl = '\n';

// global variables
int n, width_sum = 0, width[200000], height[200000], maxH1 = 0, maxH2 = 0, area = 0;
// global variables


int main()
{
    fastio; fileio();
    scanI(n);
    REP(i,n){
        scanI(width[i],height[i]);
        width_sum += width[i];
        if (height[i] >= maxH1){
            maxH2 = maxH1;
            maxH1 = height[i];
        } else if (height[i] > maxH2)
            maxH2 = height[i];
    }
    REP(i,n){
        /*int area = width_sum - width[i];
        area *= (height[i] == maxH1)*maxH2 + (height[i] != maxH1)*maxH1;*/
        outI(area = (width_sum - width[i]) * ((height[i] == maxH1)*maxH2 + (height[i] != maxH1)*maxH1), ' ');
    }
    return 0;
}
