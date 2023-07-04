class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        int ans = 0;
        
        for(auto i : mp){
            if(i.second == 1){
               ans = i.first;
                break;
            }
        }

        return ans;
    }
};