/*
Suppose I want to know how many distinct BST there are with n nodes from 0 to n-1.

If my BST has n-1 at the head, how many nodes will be on the left side? How many nodes will be on
the right side?

If my BST has n-2 at the head, how many nodes will be on the left side? How many nodes will be on
the right side?


n nodes of BST into 1, i - 1, and n - i nodes, where, 1 node is given to root, i - 1 nodes are given to left BST subtree and n - i nodes are given to right BST subtree respectively s.t overall we still have 1 + i - 1 + n - i = n nodes. 

*/


class Solution {
public:
// bottom up
    int numTrees(int n) {
        if(n <= 1){
            return 1;
        }

        vector<int> dp(n+1);

        dp[0] = dp[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int j =1; j <= i; j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
     return dp[n];
    }
};

/* recurssion
 if(n <= 1){
            return 1;
        }
        int result = 0;
        for(int i = 1; i <= n; i++){

            result += numTrees(i-1) * numTrees(n-i);
        }

        return result;
*/

/* top down

int solve(int n, vector<int> &dp){
    if(n <= 1){
        return 1;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    else{
        for(int i = 1; i <= n; i++){
            dp[n] += solve(i-1, dp) * solve(n-i, dp);
        }
    }

    return dp[n];
}
    int numTrees(int n) {

      vector<int> dp (n+1, 0);

      return solve(n, dp);

    }
*/