#include <bits/stdc++.h>
using namespace std;


/** https://codeforces.com/problemset/problem/230/B */
int main()
{
    ios_base::sync_with_stdio(0);

    bool isPrime[(int)1e6 + 1];
    memset(isPrime, true, sizeof(isPrime));
    // contains true at every prime index
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= (int)1e3; ++i)
        if (isPrime[i])
            for (int j = i*i; j <= (int)1e6; j+=i)
                isPrime[j] = false;

    int N;
    cin >> N;
    long long num;
    while (N--)
    {
        cin >> num;
        if (sqrt(num) == (int)sqrt(num))
        {
            if (isPrime[(int)sqrt(num)])
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        } else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
