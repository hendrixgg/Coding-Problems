#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=DfljaUwZsOk


// https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output(nums.size()-k+1);
        deque<int> q;
        // left index of window is at r+1 - k
        for(int r = 0; r < nums.size(); ++r)
        {
            // remove smaller values from back of deque
            while(!q.empty() && nums[q.back()] < nums[r])
                q.pop_back();
            
            // add rightmost value to back of deque
            q.push_back(r);
            
            // remove front value if from the previous window
            if(q.front() < r+1 - k)
                q.pop_front();
            
            // add new window maximum value
            if(r+1 >= k)
                output[r+1 - k] = nums[q.front()];
        }
        return output;
    }
};