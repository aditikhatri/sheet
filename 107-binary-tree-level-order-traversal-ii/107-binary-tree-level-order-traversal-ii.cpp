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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++){
                root=q.front();
                level.push_back(root->val);
                q.pop();
                if(root->left!=NULL) q.push(root->left);
                if(root->right!=NULL)q.push(root->right);
            }
            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        // or else store answer of level from end of ans vector
        //ans[n-1]=level and n--;
        return ans;
    }
};