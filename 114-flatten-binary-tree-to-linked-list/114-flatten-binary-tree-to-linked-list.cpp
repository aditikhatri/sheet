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
  
    void flatten(TreeNode* root) {
        // if(root==NULL) return ;
        // flatten(root->right);
        // flatten(root->left);
        // root->right=prev;
        // root->left=NULL;
        // prev=root;
        
        // reverese postorder vs inplace-morise
        TreeNode* prev=NULL;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
               prev=curr->left;
                while(prev->right) //finding last right
                    prev=prev->right;
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL; //imp
            }
            curr=curr->right;
        }
    }
};