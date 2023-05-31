class Solution {
public:
// count the no. of connected components

void bfs(int node, vector<vector<int>>& isConnected, vector<int> &vis){
    queue<int>q;
    q.push(node);
    vis[node] = 1;

    while(!q.empty()){
        node = q.front();
        q.pop();

        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[node][i] && !vis[i]){
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                bfs(i, isConnected, vis);
            }
        }

        return count;
    }
};

// TC = O(n^2);
// SC = O(n)