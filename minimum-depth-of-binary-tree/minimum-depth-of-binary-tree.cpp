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

    int minDepth(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }


        int Left = minDepth(root -> left);
        int Right = minDepth(root -> right);

        if(Right == 0){   // in case of no right subtree
            return Left + 1;
        }
        if(Left == 0){       // in case of no left subtree 
            return Right + 1;
        }

        return min(Left, Right) + 1;


        
    }
};