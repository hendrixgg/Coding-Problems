#include <iostream>

using namespace std;



/// CIN IS VERY SLOW!!!!!
// reads a number
template <class T>
inline void readInt(T &res){
    char c;
    res=0;
    while((c=getchar())<'0'|c>'9');
    while(c>='0'&&c<='9'){
        res=res*10+(c-'0');
        c=getchar();
    }
}

/** https://codeforces.com/problemset/problem/519/B */
int main()
{
    // even though 1<=n<=10^5 and each error 1<=e<=10^9
    // the difference is all we care about and since 10^9 fits in int
    // then no need for long long
    int n, e1=0, e2=0, tmp;
    cin >> n;

    for (int i=0; i<n; ++i)
    {
        readInt(tmp);
        e1 += tmp;
    }
    e2 = e1;
    for (int i=0; i<n-1; ++i)
    {
        readInt(tmp);
        e1 -= tmp;
    }
    e2 -= e1;
    for (int i=0; i<n-2; ++i)
    {
        readInt(tmp);
        e2 -= tmp;
    }

    printf("%d\n%d", e1, e2);

    return 0;
}
