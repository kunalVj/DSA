class Solution {
public:
// in-out degree
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> incomingEdge(n, false);

        for(auto edge : edges){
            incomingEdge[edge[1]] = true;     // mark all the vertex as true who have an incoming edge
        }

        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(incomingEdge[i]==false){    // store the vertex that do not have any incoming edge
                ans.push_back(i);
            }
        }

        return ans;
    }
};