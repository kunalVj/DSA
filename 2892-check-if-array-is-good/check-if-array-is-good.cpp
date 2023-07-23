class Solution {
public:
    bool isGood(vector<int>& nums) {
    /*    int n = nums.size();
        n--;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return false;
            }
        }
        if(nums[n]!=n){
            return false;
        }
        return true; */

        int n = *max_element(nums.begin(), nums.end());
        int maxi = 0;
        vector<int> freq(n+1, 0);
        if(nums.size() < n+1) return false;
        for(auto i : nums){
            freq[i]++;
          
        }

        for(int i = 0; i <= n; i++){
            if(freq[i] == 0 && freq[i] > 2) return false;
            if(freq[i] == 2 && i != n) return false;
            if(freq[n] != 2){
                return false;
            }
        }

        return true;


        
    }
};