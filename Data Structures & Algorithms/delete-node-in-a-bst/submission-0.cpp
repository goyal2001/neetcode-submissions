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
     TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val>key){
           root->left = deleteNode(root->left,key);
            return root;
        }
        else if(root->val==key){
            //if leaf node
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            //if 1 children
            else if(root->left==NULL && root->right!=NULL){
                TreeNode *temp=root->right;
                delete root;
                return temp;
            }
             else if(root->left!=NULL && root->right==NULL){
                TreeNode *temp=root->left;
                delete root;
                return temp;
            }
            //if 2 children
            else{
            TreeNode *temp=root->right;
            while(temp->left!=NULL)  temp=temp->left;
            root->val=temp->val;
            root->right=deleteNode(root->right,root->val);
            return root;
            }
            }
        else{
            root->right=deleteNode(root->right,key);
            return root; 
        }
        return root;
    }
};