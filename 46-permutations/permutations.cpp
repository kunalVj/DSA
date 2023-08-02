class Solution{
    public:
    void helper(int ind, vector<int> &nums, vector<vector<int>> &Result){

        if(ind==nums.size()){
            Result.push_back(nums);
            return;
        }
        
        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            helper(ind+1, nums, Result);
            swap(nums[ind], nums[i]);
        }
    }
     vector<vector<int>> permute(vector<int>& nums){
         vector<vector<int>> Result;
         helper(0, nums, Result);
         return Result;

     }

};





















/* Space complexity will be high in this approach

class Solution {
public:
void helper(vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans, int freq[] ){
if(arr.size()==nums.size()){
    ans.push_back(arr);
    return;
}
for(int i=0; i<nums.size(); i++){
    if(!freq[i]){
        arr.push_back(nums[i]);
        freq[i]=1;
        helper(nums, arr, ans, freq);
        arr.pop_back();
        freq[i]=0;
    }
}
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++) freq[i]=0;

        helper(nums, arr, ans, freq);
        return ans;
        
    }
};*/