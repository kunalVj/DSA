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
    int maxLevelSum(TreeNode* root) {
        int maxi = INT_MIN;
        int level = 0;
        int ans = 0;

        queue<TreeNode*> q;
        q.push(root);
        
// Iterate through all the nodes at level using only the q.size() number of nodes. 
//Within this inner loop, pop out all the nodes at the current level one by one, adding their values to 
//sumAtCurrentLevel and pushing the left and right children (if they exist) into the queue.

        while(!q.empty()){
            level++;
            int currLevelSum = 0;
            int size = q.size();

            while(size--){
                TreeNode* node = q.front();
                q.pop();
                currLevelSum += node -> val;

                if(node -> left){
                    q.push(node -> left);
                } 
                if(node -> right){
                    q.push(node -> right);
                }
            }

            if(maxi < currLevelSum){
                maxi = currLevelSum;
                ans = level;
            }
        }

        return ans;
    }
};