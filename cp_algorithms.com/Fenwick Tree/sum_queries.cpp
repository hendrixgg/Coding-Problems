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

struct FenwickTree {
    vector<int64_t> bit;  // binary indexed tree
    int64_t n;

    FenwickTree(int64_t size) {
        this->n = size;
        bit.assign(n, 0);
    }

    FenwickTree(const vector<int64_t>& a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int64_t sum(int64_t r) {
        int64_t ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int64_t sum(int64_t l, int64_t r) {
        return sum(r) - sum(l - 1);
    }

    void add(int64_t idx, int64_t delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
// https://atcoder.jp/contests/practice2/tasks/practice2_b
int main()
{
    int64_t n, q;
    scan2(n, q);
    FenwickTree a(n);
    for(int64_t x, i = 0; i < n; ++i)
    {
        scan2(x);
        a.add(i, x);
    }
    for(int64_t type, q1, q2; q > 0; --q)
    {
        scan2(type, q1, q2);
        if(type == 0)
        {
            a.add(q1, q2);
        }
        else // type == 1
        {
            printf("%lld\n", a.sum(q1, q2-1));
        }
    }
}