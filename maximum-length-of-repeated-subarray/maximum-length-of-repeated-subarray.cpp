class Solution {
public:
// similar to longest common subsequence

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int dp[n+1][m+1];

        int ans = 0;

        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < m+1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(nums1[i-1] == nums2[j-1]){ // same character
// then we add 1 to the previous state, which is dp[i - 1][j - 1]
// in other word, we extend the repeated subarray by 1
// e.g. a = [1], b = [1], length of repeated array is 1
//      a = [1,2], b = [1,2], length of repeated array is the previous result + 1 = 2
                   
                    dp[i][j] = 1 + dp[i-1][j-1];

// record the max answer here
                    ans = max(ans, dp[i][j]);
                }
                else{
// since both character is not equal, which means we need to break it here. hence, set dp[i][j] to 0

                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }
};