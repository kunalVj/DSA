class Solution {
public:
void solve(int curr, int n, int k, vector<int> &arr,  vector<vector<int>> &ans){
    if(arr.size() == k){    // base case, we stop with the recursion and add it to our final result ans
        ans.push_back(arr);
        return;
    }

    for(int i = curr; i <= n; i++){
        arr.push_back(i);
        solve(i+1, n, k, arr, ans);
        arr.pop_back();
    }

}
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        vector<vector<int>> ans;

        solve(1, n, k, arr, ans);

        return ans;

    }
};