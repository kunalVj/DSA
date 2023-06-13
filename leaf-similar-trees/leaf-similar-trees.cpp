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
void dfs(TreeNode* root, vector<int> &leaves){
    if(root == NULL){
        return;
    }

    if(root -> left == NULL && root -> right == NULL){
        leaves.push_back(root -> val);
    }

    dfs(root -> left, leaves);
    dfs(root -> right, leaves);

}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leavesOf1;
        vector<int> leavesOf2;

        dfs(root1, leavesOf1);
        dfs(root2, leavesOf2);

        if(leavesOf1 == leavesOf2){
            return true;
        }

        return false;
    }
};