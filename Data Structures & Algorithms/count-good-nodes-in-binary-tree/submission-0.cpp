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
    int ans=0;
    void count(TreeNode *root,int max){
        if(!root) return;
        if(root->val<max){
             count(root->left,max);
            count(root->right,max);
        }
        else if(root->val>=max){
            ans++;
            count(root->left,root->val);
            count(root->right,root->val);
        }
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        ans=1;
        count(root->left,root->val);
        count(root->right,root->val);
        return ans;
    }
};
