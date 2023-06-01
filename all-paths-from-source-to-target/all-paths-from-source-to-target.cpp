class Solution {
public:
void dfs(vector<vector<int>> &ans, vector<int> path, vector<vector<int>>& graph, int source, int target){
    path.push_back(source);  // store the node in path that we are processing

    if(source == target){    // when target reached then store that path in ans
        ans.push_back(path);
    }
    else{
        for(auto it : graph[source]){     // process neighbor that leads to target
            dfs(ans, path, graph, it, target);
        }
    }
    path.pop_back();    // backtrack
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        
        int target = graph.size() - 1;

        dfs(ans, path, graph, 0, target);

        return ans;

    }
};
/*
 O(n * 2^n) where n = number of nodes.
Because for each node (n) we are exploring all the possible paths (2^n). And as for each node we have 2 possibilities (either take it or do not take it).
So, for n nodes total number of paths = 2 * 2 * .. n times = 2^n
*/ 