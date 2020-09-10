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
    void Helper(TreeNode* root,int cur){
        if(!root) return;
        int temp = 2*cur + root->val;
        if(!root->left && !root->right){
            ans+=temp;
            return;
        }
        Helper(root->left,temp);
        Helper(root->right,temp);
    }

    int sumRootToLeaf(TreeNode* root) {
        Helper(root,0);
        return ans;
    }
};
