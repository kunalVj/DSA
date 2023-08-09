class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curr_sum = 0;
        int start = 0;
        int end = 0;
        int length = INT_MAX;

        if(nums.size() < 1)
        return 0;

        if(nums.size() == 1 && nums[0] >= target)
        return 1;

        
            while(end < nums.size()){
                    curr_sum += nums[end];
                    end++;
                while(curr_sum >= target){
                    length = min(length, end - start );
                    curr_sum -= nums[start];
                    start++;
                }

            }
        
            if(length == INT_MAX){
            return 0;
            }
        
        return length;

    }
};