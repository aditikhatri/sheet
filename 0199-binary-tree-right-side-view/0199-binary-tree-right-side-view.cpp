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
    vector<int> rightSideView(TreeNode* root)
    {
        if(root==NULL)
        {
            return {};
        }
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0)
        {
           int s=q.size();
            v.push_back(q.front()->val);
            while(s>0)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->right) 
                {
                    q.push(node->right);
                }
                if(node->left) 
                {
                    q.push(node->left);
                }
                s--;
            }
        }
        return v;
        
    }
};