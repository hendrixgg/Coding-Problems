#include <bits/stdc++.h>
using namespace std;

constexpr int buff_sz = (1<<12)+1;
char _inp[buff_sz], *_pinp=_inp, _; bool _ssign;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, buff_sz, stdin)]='\0', *_pinp++))
#define _scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
#define _scan2(x) do{while((x=getchar())<'-'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
template<typename T> inline void scan(T& x){_scan(x);}
template<typename Head, typename... Tail> inline void scan(Head& h, Tail&... t){_scan(h);scan(t...);}
template<typename T> inline void scan2(T& x){_scan2(x);} // for positive integers only
template<typename Head, typename... Tail> inline void scan2(Head& h, Tail&... t){_scan2(h);scan2(t...);}

int main()
{
    int n, t, pos = 1;
    scan(n, t);
    for(int i = 1, d; i < n && pos < t; ++i)
    {
        scan(d);
        if(i == pos) pos += d;
    }
    if(pos == t) printf("YES\n");
    else printf("NO\n");
    return 0;
}