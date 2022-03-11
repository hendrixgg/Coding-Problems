#include <bits/stdc++.h>

// https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        const long long N = nums.size();
		const long long actual_sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        const long long expected_sum = N*(N+1)/2;
        return expected_sum - actual_sum;
    }
};