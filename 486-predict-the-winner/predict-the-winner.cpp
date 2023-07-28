class Solution {
public:
int diff(vector<int> &nums, int left, int right, int n){
    if(left == right){
        return nums[left];
    }

    int leftScore = nums[left] - diff(nums, left + 1, right, n);
    int rightScore = nums[right] - diff(nums, left, right - 1, n);

    return max(leftScore, rightScore);
}
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();

        return diff(nums, 0, n - 1, n) >= 0;  // This call is from the perspective of the first player, and the first player is the winner if the players have the same score (difference of 0).

    }
};