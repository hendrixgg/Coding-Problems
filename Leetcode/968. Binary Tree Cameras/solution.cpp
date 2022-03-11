#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// https://leetcode.com/problems/binary-tree-cameras/
class Solution {
public:
    int minCameraCover(TreeNode* root) 
	{
		int cameras = 0;
        // 1 = camera required in parent.
        // 2 = camera below.
        // 3 = camera installed.
        function<int(TreeNode*)> dfs = [&](TreeNode* at)
        {
            if(at == nullptr)
                return 2;
            // get state of children
            const int left = dfs(at->left);
            const int right = dfs(at->right);
            if(left == 1 || right == 1) // if a child said camera reuired in parent.
            {
                ++cameras;              // add to camera count.
                return 3;               // return "camera installed"
            }
            if(left == 3 || right == 3) // if a child had a camera installed.
            {
				return 2;               // return "camera below"
			}
            // both children have cameras below.
            return 1;	// return "camera requied in parent"
        };
        return (dfs(root) == 1) + cameras;
    }
};

class Solution2 {
	// returns {cameras in subtree, {have camera, have camera below} }
	pair<int, pair<bool, bool>> dfs(TreeNode* at)
	{
        // a null node is covered since it doesn't need a camera
        if(at == nullptr)
            return {0, {false, true}};
        
        // look at children
        auto [left_cams, l_info] = dfs(at->left);
        auto [right_cams, r_info] = dfs(at->right);
        
        // put a camera here if a child has no camera and has no camera below
        const bool camera_here = (!l_info.first && !l_info.second) || (!r_info.first && !r_info.second);
        
        // we have a camera below if a child has a camera
        const bool camera_below = l_info.first || r_info.first;
        
        // number of cameras in subtree including this node
		const int cameras = left_cams + right_cams + camera_here;
        
		return {cameras, {camera_here, camera_below}};
	}
public:
    int minCameraCover(TreeNode* root) 
	{
        auto [cameras, info] = dfs(root);
		// if there is no camera below and root doesn't have a camera, then its needs a camera
		const bool need_camera = !info.first && !info.second;
		return cameras + need_camera;
    }
};