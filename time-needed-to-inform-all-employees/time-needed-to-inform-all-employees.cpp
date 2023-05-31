class Solution {
public:
int maxTime = INT_MIN;

void dfs(int currNode, int time,  vector<int> adj[], vector<int> &informTime){
    maxTime = max(maxTime, time); // max time taken to deliver the news to employee

    for(auto subordinate : adj[currNode]){  // iterate over adjacent nodes of current node with the time it took to get the news to the subordinate employee
        dfs(subordinate, time + informTime[currNode], adj, informTime);
    }
}
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
            vector<int> adj[n];

             for(int i = 0; i < n; i++){ // adjaceny list where ech index store the ids of subordinate employee
                 if(manager[i] != -1){   
                     adj[manager[i]].push_back(i);
                 }
             }

             dfs(headID, 0, adj, informTime);

             return maxTime;
    }
};