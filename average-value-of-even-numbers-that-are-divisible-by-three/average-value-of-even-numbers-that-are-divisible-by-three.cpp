class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int total_num = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                if(nums[i] % 3 == 0){
                    sum += nums[i];
                    total_num++;
                }
            }
        }

       if(total_num == 0){
           return 0;
       }

       return sum / total_num;
    }
};