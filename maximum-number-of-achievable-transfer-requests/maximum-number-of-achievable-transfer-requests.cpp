class Solution {
public:
void solve(vector<vector<int>> &requests, vector<int> &indegree, int n, int &ans, int index, int count){
    if(index == requests.size()){
        for(int i = 0; i < n; i++){
            if(indegree[i] != 0){
                return;
            }
        }

        ans = max(ans, count);
        return;
    }

    indegree[requests[index][0]]--;
    indegree[requests[index][1]]++;

    solve(requests, indegree, n, ans, index + 1, count + 1);

    indegree[requests[index][0]]++;
    indegree[requests[index][1]]--;

    solve(requests, indegree, n, ans, index + 1, count);
}
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n, 0);

        int ans = 0;

        solve(requests, indegree, n, ans, 0, 0);

        return ans;
    }
};