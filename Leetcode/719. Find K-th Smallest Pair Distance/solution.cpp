#include <bits/stdc++.h>
using namespace std;


// original implementation
class Solution1 {
    int count_smaller(vector<int>& a, int x)
    {
        int total = 0, pos = 0;
        for(int i = 0; i < a.size(); ++i)
        {
            while(pos < a.size() && a[pos] - a[i] < x)
                ++pos;
            total += pos - i - 1;
        }
        return total;
    }
public:
    int smallestDistancePair(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int lo = 0, hi = a[a.size()-1] - a[0];
        while(lo <= hi)
        {
            int x = (lo + hi)>>1;
            int smaller = count_smaller(a, x);
            int equal = count_smaller(a, x+1) - smaller;
            if(smaller < k && smaller + equal >= k)
                return x;
            if(smaller >= k)
                hi = x - 1;
            if(smaller + equal < k)
                lo = x + 1;
        }
        return 0;
    }
};

// optimized versions
class Solution2 {
    // counts the number of distances between elements that are less than x
    // returns true if this count is greater than or eual to k
    int count_smaller_is_greater_or_equal_to_k(vector<int>& a, int x, int k)
    {
        int total = 0, pos = 0;
        for(int i = 0; i < a.size(); ++i)
        {
            while(pos < a.size() && a[pos] - a[i] < x)
                ++pos;
            total += pos - i - 1;
            if(total >= k)
                return true;
        }
        return total >= k;
    }
public:
    int smallestDistancePair(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int ans = -1, lo = 0, hi = a[a.size()-1] - a[0];
        while(lo <= hi)
        {
            int x = (lo + hi)>>1;
            if(count_smaller_is_greater_or_equal_to_k(a, x+1, k))
            {
                ans = x;
                hi = x - 1;
                continue;
            }
            lo = x + 1;
        }
        return ans;
    }
};

class Solution3 {
    // counts the number of distances between the elements that are less than x
    // returns true if that count is less than k
    int count_smaller_less_than_k(vector<int>& a, int x, int k)
    {
        int total = 0, pos = 0;
        for(int i = 0; i < a.size(); ++i)
        {
            while(pos < a.size() && a[pos] - a[i] < x)
                ++pos;
            total += pos - i - 1;
            if(total >= k)
                return false;
        }
        return total < k;
    }
public:
    int smallestDistancePair(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int ans = -1, lo = 0, hi = a[a.size()-1] - a[0];
        while(lo <= hi)
        {
            int x = (lo + hi)>>1;
            if(count_smaller_less_than_k(a, x, k))
            {
                ans = x;
                lo = x+1;
                continue;
            }
            hi = x - 1;
        }
        return ans;
    }
};