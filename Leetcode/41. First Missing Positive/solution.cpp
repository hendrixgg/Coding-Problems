#include <bits/stdc++.h>

// https://leetcode.com/problems/first-missing-positive/
class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
		const long long N = nums.size();
        std::vector<bool> is_there(N+1);
        for(const int& num : nums)
            if(1 <= num && num <= N)
                is_there[num] = true;
        for(int num = 1; num <= N; ++num)
        {
            if(!is_there[num])
                return num;
        }
		// below code from this video: https://youtu.be/hnV0IhnEqH4
		// long long curr, next;
		// for(int i = 0; i < N; ++i)
		// {
		// 	curr = nums[i];
		// 	while (0 <= curr - 1 && curr - 1 < N && curr != (next = nums[curr - 1]))
		// 	{
		// 		nums[curr - 1] = curr;
		// 		curr = next;
		// 	}
		// }
		// for(int i = 0; i < N; ++i)
		// {
		//     if(nums[i] != i + 1)
		// 		return i + 1;
		// }
		return N + 1;
    }
};