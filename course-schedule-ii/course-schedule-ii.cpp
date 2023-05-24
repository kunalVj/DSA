class Solution {
public:
// topological sort
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int n = numCourses;
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        queue<int> q;
// make a adjacency list and find the indegree of every vertex
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);

            indegree[u]++;
        }

        for(int i = 0; i < n; i++){  // push the vetices with 0 indegree as they will be our starting point
            if(indegree[i] == 0){
                q.push(i);
            }
        }


        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
// if there is a cycle then topo.size will be not equal to total vertex or numCourses, if it's equal then there is no cycle, means we can complete the course
        if(topo.size() == n){
            return topo;
        }

        return {}; // return empty array in case we are not able to complete courses
    }
};

// TC - O(V+E)
// SC - O(V+E)