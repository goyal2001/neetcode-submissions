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
    TreeNode* buildNode(const vector<int>& preorder, int low, int high, int& index, const unordered_map<int,int>& order){
        if(low>high) return nullptr;
        TreeNode* root = new TreeNode(preorder[index]);
        int id = order.at(preorder[index]); index++;
        root->left = buildNode(preorder, low, id-1, index, order);
        root->right = buildNode(preorder, id+1, high, index, order);
        return root;
    }
    TreeNode* buildTree(const vector<int>& preorder,const vector<int>& inorder) {
        int n = inorder.size(); //4
        unordered_map<int,int> order;
        for(int i = 0; i<n; i++){
            order[inorder[i]] = i; // 2->0 , 1-> 1 , 3->2, 4 -> 3
        }
        int index = 0;
        return buildNode(preorder, 0, n-1, index, order);
    }
};
