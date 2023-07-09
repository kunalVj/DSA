class Solution {
    public:
        void findcombinationsum(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
            if(ind==arr.size()){
                if(target==0){
                    ans.push_back(ds);
                }
                return;
            }
            //pick the element
            if(arr[ind]<=target){
                ds.push_back(arr[ind]);
                findcombinationsum(ind, target-arr[ind], arr, ans, ds);
                ds.pop_back();
            }
            findcombinationsum(ind+1, target, arr, ans, ds);
            
        }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ds;
        findcombinationsum(0, target, candidates, ans, ds);
        return ans;   
        
    }
};

//time complexcity : exponential  2^(t) * k
// we have to do pick/not pick for t times, k is the average length of combination

// space complexcity : k * x
// k is the average length of the combination, and x is the no. of combination
