#include <bits/stdc++.h>


class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        // you have sum of 0 in the position before index 0
        std::unordered_map<int, int> pre_sum_mod_k{{0, -1}};
        int prefix_modk = 0, idx = 0;
        for (const int &num : nums)
        {
            prefix_modk = (prefix_modk+num) % k;
            if(pre_sum_mod_k.count(prefix_modk))
            {
                if(idx - pre_sum_mod_k[prefix_modk] > 1)
                {
                    return true;
                }
            }
            else
            {
                pre_sum_mod_k[prefix_modk] = idx;
            }
            ++idx;
        }

		return false;
    }
};

template <const int n>
struct hash_map
{
	// need N = (2^n)-1 because we are using & N instead of % N
	const int N = (1 << n) - 1;
	int key[1 << n]{}, val[1 << n]{};
    void init(const int sentinel)
    {
        for(int& v : val)
            v = -999;
    }
	int &operator[](const int k)
	{
		int c = k & N, cnt = 1;
		while (key[c] != k && val[c] != -999)
		{
			c = (c + cnt) & N;
			cnt += cnt;
		}
		key[c] = k;
		return val[c];
	}
};

class Solution2 {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        // you have sum of 0 in the position before index 0
        hash_map<18> mp;
        mp.init(-999);
		mp[0] = -1;
        int prefix_modk = 0, idx = 0;
        for (const int &num : nums)
        {
            prefix_modk = (prefix_modk+num) % k;
            if(mp[prefix_modk] != -999)
            {
                if(idx - mp[prefix_modk] > 1)
                {
                    return true;
                }
            }
            else
            {
                mp[prefix_modk] = idx;
            }
            ++idx;
        }

		return false;
    }
};