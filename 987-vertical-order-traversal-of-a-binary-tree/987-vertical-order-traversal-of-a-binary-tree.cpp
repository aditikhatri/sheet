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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,map<int,vector<int>>> map; // (x --> (y --> (elements at this location)))
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int level = 0; // y coordinate
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto e = q.front();q.pop(); // e.first is the element, e.second is it's x coordinate
                map[e.second][level].push_back(e.first->val);
                mini = min(mini, e.second);
                maxi = max(maxi, e.second);
                if(e.first->left != NULL){
                    q.push({e.first->left, e.second-1});
                }
                if(e.first->right != NULL){
                    q.push({e.first->right, e.second+1});
                }
            }
            level++;
        }
        vector<vector<int>> op(maxi-mini+1);
        int inx = 0;
        for(int i = mini;i<=maxi;i++){
            vector<int> vv;
            for(auto e : map[i]){
                sort(e.second.begin(), e.second.end());
                for(auto ee : e.second){
                    vv.push_back(ee);
                }
            }
            op[inx] = vv;
            inx++;
        }
        return op;
    }
};