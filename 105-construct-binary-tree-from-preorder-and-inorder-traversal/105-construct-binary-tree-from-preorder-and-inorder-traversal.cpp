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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int ,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i; //search inorder
        }
        TreeNode* root= helper(preorder,0,n-1,inorder,0,n-1,mp);
        
        return root;
    }
    TreeNode*helper(vector<int>& preorder, int ps,int pe,vector<int>& inorder,int is,int ie,map<int,int>&mp){
        if(is>ie || ps>pe) return NULL;
        // declare root
        TreeNode*root= new TreeNode(preorder[ps]);
        int idx=mp[root->val]; //inorder ke liye
        int diff= idx-is;
        root->left= helper(preorder,ps+1,ps+diff,inorder,is,idx-1,mp);
        root->right=helper(preorder,ps+diff+1,pe,inorder,idx+1,ie,mp);
        return root;
    }
};