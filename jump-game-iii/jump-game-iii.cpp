class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);

        vector<int> vis(arr.size(), 0);
        vis[start] = 1;

        if(arr[start] == 0){
            return true;
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(arr[curr] == 0){
                return true;
            }

            int next_index = curr - arr[curr];
            if(next_index >= 0 && vis[next_index] == 0){
                q.push(next_index);
                vis[next_index] = 1;
            }

            next_index = curr + arr[curr];
            if(next_index < arr.size() && vis[next_index] == 0){
                q.push(next_index);
                vis[next_index] = 1;
            }
        }

        return false;
    }
};

// TC = O(N);
// SC = O(N);