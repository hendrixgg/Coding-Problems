#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY queries
 */

vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> ans(queries.size());
    for(int a = 0, d = queries[a]; a < int(queries.size()); ++a, d = queries[a])
    {
        deque<int> q;
        // add first d elements into the deque
        for(int i = 0; i < d; ++i)
        {
            while(!q.empty() && arr[q.back()] < arr[i])
                q.pop_back();
            q.push_back(i);
        }
        ans[a] = arr[q.front()];
        // loop for each next subarray endpoint
        for(int j = d; j < int(arr.size()); ++j)
        {
            // pop off element no longer in range
            if(q.front() == j-d)
                q.pop_front();
            // remove elements less than arr[i] to maintain non-increasing order
            while(!q.empty() && arr[q.back()] < arr[j])
                q.pop_back();
            // insert element
            q.push_back(j);
            // take the maximum element, and maintain the minimum of all maximums
            ans[a] = min(ans[a], arr[q.front()]);//q.front is always the maximum element
        }
    }
    return ans;
}

// problem: https://www.hackerrank.com/challenges/queries-with-fixed-length/problem
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> arr(n), queries(q), answer;
    for(int& a : arr)
        scanf("%d", &a);
    for(int& query : queries)
        scanf("%d", &query);
    
    answer = solve(arr, queries);
    for(int& ans : answer)
        printf("%d\n", ans);

    return 0;
}