class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        int n = nums.size();
        for(auto num : nums){
           if(++hash[num] > n/2){
               return num;
           }

        }
        return 0;
    }
};