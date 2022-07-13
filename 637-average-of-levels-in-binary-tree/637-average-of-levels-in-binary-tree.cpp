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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                level.push_back(root->val);
                if(root->left!=NULL) q.push(root->left);
                if(root->right!=NULL)q.push(root->right);
            }
            double sum=0,avg;
            for(auto x:level){
                sum+=x;//level can range 1-4 not nessly 2
            }
            avg=(sum/level.size());
            ans.push_back(avg);
        }
        return ans;
    }
};