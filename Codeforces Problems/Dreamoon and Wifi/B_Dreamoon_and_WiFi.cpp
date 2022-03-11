#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define PI 3.141592653589793238L
const char nl = '\n';

int nCk(int n, int k) {
    long double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s1, s2;
    cin >> s1 >> s2;
    int sent = 0, rec = 0, options = 0;
    for(const char& c : s1)
        sent += (c == '+') - (c == '-');
    for(const char& c : s2)
        c == '?' ? ++options : rec += (c == '+') - (c == '-');

    int gain = abs(sent - rec), need = 0;
    for(int have = -options; have < gain; ++need, have += 2);
    cout << setprecision(12) << fixed << ld(nCk(options, need)) / ld(1 << options);
    return 0;
}