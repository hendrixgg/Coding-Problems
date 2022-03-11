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
#define ROF(a, b, c) for (int a = b; a > c-1; --a)
#define REP(a, n) for (int a = 0; a < n; ++a)
using namespace std;

/**
test1:
3
1 2 3
1 3

ans = 3


test 2:
5
1 2 3 4 1
1 3

ans=4

https://codeforces.com/problemset/problem/939/C
*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s, f, maxp=0, startTime=0, range;
    cin >> n;
    int ppl[2*n + 1] = {0};

    FOR(i,1,n)
    {
        cin >> ppl[i];
        ppl[i+n] = ppl[i];
    }

    cin >> s >> f;

    FOR(i,1, 2*n) ppl[i] += ppl[i-1]; // prefix sum

    range = f-s;
    int hour = 1;
    ROF(i,n+1,1)
    {
        int prev = maxp;
        maxp = max(maxp, ppl[i+s+range-2] - ppl[i+s-2]);
        if (maxp > prev)
            startTime = hour;
        ++hour;
    }

    cout << startTime << endl;
    return 0;
}
