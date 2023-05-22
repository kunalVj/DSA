// if we find a cycle we dont, include it's nodes in safe node, anyone who is part of cycle is not safe node
// any node who leads to cycle can not be safe node


class Solution {
public:
bool dfs(int node, vector<vector<int>>& graph, vector<int> &vis, vector<int> &pathVis, vector<int> &check){
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it : graph[node]){  // check if it's cycle 
        if(vis[it] == 0){
            if(dfs(it, graph, vis, pathVis, check) == true){
                return true;
            }
        }
        else if(vis[it] == 1 && pathVis[it] == 1){
            return true;
        }
    }
    check[node] = 1;  // mark the node that are included in path that lead to terminal node and not part of cycle

    pathVis[node] = 0;

    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n, 0);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathVis, check);
            }
        }

        for(int i = 0; i < n; i++){   // push the safe node in ans
            if(check[i] == 1){
                ans.push_back(i);
            }
        }

        return ans;
        
    }
};
// tc = O(V + E)
// sc = O(N)