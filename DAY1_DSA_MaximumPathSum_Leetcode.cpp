/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int ans  = INT_MIN;
    
    int help (TreeNode* root){
        
        if(root==NULL){
            return 0 ;
        }
        int l = help(root->left);
        int r = help(root->right);
        
        int temp = max(max(l,r)+root->val , root->val);
        int res = max(temp , l+r+root->val);
        ans = max(ans , res);
        
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        help(root);
        return ans;
    }
};



// Problem statement :
// https://leetcode.com/problems/binary-tree-maximum-path-sum