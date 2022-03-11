#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define PI 3.141592653589793238L
const char nl = '\n';

bool comp(const array<int, 3>& a, const array<int, 3>& b)
{
    if(a[1] != b[1])
        return a[1] < b[1];
    return a[2] < b[2];
}

void print_solution(int i, int chosen[], array<int, 3> envelope[])
{
    if (chosen[i] == i)
    {
        cout << envelope[i][0] << " ";
        return;
    }
    print_solution(chosen[i], chosen, envelope);
    cout << envelope[i][0] << " ";
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, w, h, good = 0;
    cin >> n >> w >> h;
    // {w, h, i}
    array<int, 3> envelope[n];
    for(int i = 1; i <= n; ++i)
    {
        cin >> envelope[good][1] >> envelope[good][2];
        envelope[good][0] = i;
        if(envelope[good][1] > w && envelope[good][2] > h)
            ++good;
    }
    // all envelopes are too small
    if(good == 0)
    {
        cout << "0";
        return 0;
    }
    // sort by increasing width, in case of a tie, increasing hight
    sort(envelope, envelope+good, comp);

    int top = 0, dp[good+1]{1, 0}, chosen[good+1]{};

    for(int i = 1; i < good; ++i)
    {
        dp[i] = 1, chosen[i] = i;
        for(int j = i-1; j >= 0; --j)
        {
            if(envelope[j][1] < envelope[i][1] && envelope[j][2] < envelope[i][2] && dp[j]+1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                chosen[i] = j;
            }
        }
        if(dp[i] > dp[top])
            top = i;
    }

    cout << dp[top] << nl;
    print_solution(top, chosen, envelope);
    return 0;
}