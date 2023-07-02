class Solution {
public:
void solve(vector<vector<int>> &requests, vector<int> &indegree, int n, int &ans, int index, int count){
    if(index == requests.size()){
        // Check if all buildings have an in-degree of 0.
        for(int i = 0; i < n; i++){
            if(indegree[i] != 0){
                return;
            }
        }

        ans = max(ans, count);
        return;
    }

// Consider this request, increment and decrement for the buildings involved.
    indegree[requests[index][0]]--;
    indegree[requests[index][1]]++;

// Move on to the next request and also increment the count of requests.

    solve(requests, indegree, n, ans, index + 1, count + 1);

// Backtrack to the previous values to move back to the original state before the second recursion.

    indegree[requests[index][0]]++;
    indegree[requests[index][1]]--;

 // Ignore this request and move on to the next request without incrementing the count.

    solve(requests, indegree, n, ans, index + 1, count);
}
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n, 0);

        int ans = 0;

        solve(requests, indegree, n, ans, 0, 0);

        return ans;
    }
};

// tc = O(2^n * m) , n = np. of req, m = no.of buildings
// sc = O(n + m)