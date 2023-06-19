class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
// if my sum is odd then it is impossible to find the partitioning because odd numbers don't have pair.

        if(sum % 2 != 0){
            return false;
        }
// if sum is even then there are changes of doing partitioning so the easiest way will be to make the sum half and then find the sum in the given array.

// Then by doing this the problem will be reduced to a simple 01 Knapsack of finding a subset sum in an array.
        else{
            int target = sum/2;
            bool dp[n+1][target+1];

            for(int i = 0; i < n+1; i++){
                for(int j = 0; j < target+1; j++){
                   if(i == 0) dp[i][j] = false;
                   if(j == 0) dp[i][j] = true;
                }
            }

            for(int i = 1; i < n+1; i++){
                for(int j = 1; j < target+1; j++){

                    if(nums[i-1] <= j){
                        dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }

            return dp[n][target];
        }
    }
};