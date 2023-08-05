class Solution {
public:
int solve(int n, vector<int> &dp){
    if(n <= 1){
        return 1;
    }

    if(!dp[n]){
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