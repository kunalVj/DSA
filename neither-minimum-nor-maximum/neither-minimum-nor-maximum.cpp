class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() < 3){
            return -1;
        }
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i : nums){
        mini = min(mini, i);
        maxi = max(maxi, i);
        }

        for(int i : nums){
            if(i != mini && i != maxi){
                return i;
            }
        }
        
        return -1;
    }
};