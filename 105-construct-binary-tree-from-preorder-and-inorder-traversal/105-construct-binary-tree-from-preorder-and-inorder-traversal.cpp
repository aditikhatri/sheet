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
       int preIndex=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return help(preorder,inorder,0, n-1);
    }
    
    TreeNode* help(vector<int>& preorder, vector<int>& inorder,int left,int right)
    {
        
      
        
        if(left>right)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int inIndex=0;
        for(int j=left;j<=right;j++)
        {
            if(inorder[j]==root->val)
            {
                inIndex=j;
                break;
            }
        }
        root->left = help(preorder,inorder,left,inIndex-1);
        root->right = help(preorder,inorder,inIndex+1,right);
        return root;
    
        
    }
};