/*
    from: https://ideone.com/qdj1jS
    Vishal Raj
    Indian Institute of Technology Kharagpur
*/
#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define FOR(i, l, r) for (int i = l - (l > r); i != r - (l > r); i += 1 - 2 * (l > r))
#define pb push_back
#define all(X) (X).begin(), (X).end()
#define xx first
#define yy second
#define ii pair<int, int>
#define vii vector<ii>

int ans = 0;

std::random_device                  rand_dev;
std::mt19937                        rng(rand_dev());
// generates a random integer on the interval [range_from, range_to]
template<typename T>
T random(const T range_from, const T range_to)
{
    std::uniform_int_distribution<T>    distribution(range_from, range_to);
    return distribution(rng);
}

void solve()
{
    vi v(12, 0);
    int qq = 0;
    vi qu(8, -1);
    vi se(4, -1);
    vi fi(2, -1);
    FOR(i, 0, 4)
    {
        int k = i * 3;
        FOR(j, k, k + 3)
        {
            int l = j + 1;
            if (l == k + 3)
                l = k;
            if (random(0,1))
            {
                v[l]++;
            }
            else
            {
                v[j]++;
            }
        }
        vii u(3, {0, 0});
        FOR(j, 0, 3)
        u[j] = {v[k + j], k + j};
        sort(all(u));
        int out = 0;
        if (u[0].xx == u.back().xx)
        {
            out = random(0,2);
        }
        FOR(j, 0, 3)
        {
            if (j != out)
            {
                qu[qq++] = u[j].yy;
            }
        }
    }
    qq = 0;
    FOR(i, 0, 4)
    {
        int k = i * 2;
        if (random(0,1))
        {
            v[qu[k + 1]]++;
            se[qq++] = qu[k + 1];
        }
        else
        {
            v[qu[k]]++;
            se[qq++] = qu[k];
        }
    }
    qq = 0;
    FOR(i, 0, 2)
    {
        int k = i * 2;
        if (random(0,1))
        {
            fi[qq++] = se[k + 1];
            v[se[k + 1]]++;
        }
        else
        {
            fi[qq++] = se[k];
            v[se[k]]++;
        }
    }
    qq = 0;
    if (random(0,1))
    {
        v[fi[1]]++;
        ans += v[fi[1]];
    }
    else
    {
        v[fi[0]]++;
        ans += v[fi[0]];
    }
}

int main()
{
    int times;
    cin >> times;
    FOR(i, 0, times)
        solve();

    cout << "simulated: " << ans * 1.0 / times << "\n";
    cout << "expected: " << 35.0/8.0 << '\n';
    return 0;
}