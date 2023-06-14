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
void inOrder(TreeNode* root, int &mini, TreeNode* &prev){
    if(root == NULL){
        return;
    }

    inOrder(root -> left, mini, prev);

    if(prev != NULL){
        mini = min(mini, root -> val - prev -> val);
    }
    prev = root;

    inOrder(root -> right, mini, prev);
}
    int getMinimumDifference(TreeNode* root) {
       TreeNode* prev = NULL;
       int minDiff = INT_MAX;

       inOrder(root, minDiff, prev);
       return minDiff;
       
    }
};