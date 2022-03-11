#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/koko-eating-bananas/
class Solution
{
public:
	int minEatingSpeed(vector<int> &piles, int h)
	{
		int answer;
		// binary search over all k in the inclusive range [1,max(piles)]
		for (int k, lo = 1, hi = *max_element(piles.begin(), piles.end()), sum_time; lo <= hi;)
		{
			k = lo + ((hi - lo) >> 1), sum_time = 0;
			for (const int &p : piles)
			{
				sum_time += (p + k - 1) / k;
			}
			if (sum_time <= h)
			{
				answer = k;
				hi = k - 1;
			}
			else
			{
				lo = k + 1;
			}
		}
		return answer;
	}
};