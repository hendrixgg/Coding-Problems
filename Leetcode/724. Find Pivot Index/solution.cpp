#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // the sum of the array to the left of index i
        int suml = 0;
        // the sum of the array to the right of index i
        int sumr = 0;
        
        for(int i = 0; i < nums.size(); ++i)
            sumr += nums[i];
        
        for(int i = 0; i < nums.size(); ++i)
        {
            sumr -= nums[i];
            if(suml == sumr)
                return i;
            suml += nums[i];
        }
        return -1;
    }
};