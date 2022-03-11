#include <bits/stdc++.h>
using namespace std;

// returns the sum of primes in range [0,n]
uint64_t sum_primes(uint32_t n) {
    const uint32_t S = 10000;

    vector<uint32_t> primes;
    uint32_t nsqrt = sqrt(n);
    vector<uint8_t> is_prime(nsqrt + 2, true);
    for (uint32_t i = 2; i <= nsqrt; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (uint32_t j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    uint64_t result = 0;
    vector<uint8_t> block(S);
    for (uint32_t k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        // the first number in this block
        const uint32_t start = k * S;
        for (const uint32_t& p : primes) {
            uint32_t start_idx = (start + p - 1) / p;
            uint32_t j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (uint32_t i = 0; i < S && start + i <= n; ++i) {
            if (block[i])
                result += start + i;
        }
    }
    return result;
}

int main()
{
    cerr << "[Program Start]" << '\n';
    clock_t start_t = clock();

    cout << sum_primes(2e6 - 1) << '\n';

    cerr << "[Time Elasped: " << (clock() - start_t) << " ms]" << '\n';
    return 0;
}