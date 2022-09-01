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
    int  goodCount(TreeNode* root,int max_val)
    {
        if(!root)
        {
            return 0;
        }
        else
        {
            int left = goodCount(root->left,max(max_val,root->val));
            int right = goodCount(root->right,max(max_val,root->val));
            if(root->val >= max_val)
            {
                return 1+ left+right;
            }
            else
            {
                return left + right;
            }
        }
    }
    int goodNodes(TreeNode* root) {
        return goodCount(root,-100000);
    }
};