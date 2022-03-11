#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int subarraySum(vector<int> &nums, int k)
	{
		int ans = 0, prefix = 0;
		// if(prefix_sum - previous_prefix_sum - k == 0) we found a match
		// since there can be multiple prefix_sums with the same sum, store the frequency of each prefix_sum
		unordered_map<int, int> pre_sum_freq;
		pre_sum_freq.emplace(0, 1); // can have a prefix sum of 0 if we take 0 elements
		for (const int &num : nums)
		{
			prefix += num;
			ans += pre_sum_freq[prefix - k];
			++pre_sum_freq[prefix];
		}

		return ans;
	}
};

class Solution2 {
public:
	int subarraySum(vector<int> &nums, int k)
	{
		int ans = 0, sum = 0;
		for (auto i = nums.begin(); i < nums.end(); i++, sum = 0)
			for (auto j = i; j < nums.end(); j++)
				if ((sum += *j) == k)
					++ans;
		return ans;
	}
};

template <const int n>
struct Hash
{
	// need N = (2^n)-1 because we are using & N instead of % N
	const int N = (1 << n) - 1;
	int key[1 << n]{}, val[1 << n]{};
	int &operator[](const int k)
	{
		int c = k & N, cnt = 1;
		while (key[c] != k && val[c] != 0)
		{
			c = (c + cnt) & N;
			cnt += cnt;
		}
		key[c] = k;
		return val[c];
	}
};
class Solution3
{
public:
	int subarraySum(vector<int> &nums, int k)
	{
		int ret = 0, prefix_sum = 0;
		Hash<16> mp;
		++mp[0];
		for (const int &num : nums)
		{
			prefix_sum += num;
			ret += mp[prefix_sum - k];
			++mp[prefix_sum];
		}
		return ret;
	}
};