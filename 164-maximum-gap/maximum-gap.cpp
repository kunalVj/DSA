class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        sort(nums.begin(), nums.end());

        int diff = INT_MIN;

        for(int i = 0; i < nums.size() - 1; i++){
            diff = max((nums[i+1] - nums[i]), diff);
        }

        return diff;
    }
};