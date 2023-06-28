class Solution {
public:
// use dijkstra algorithim

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }
//Initialize a distance array to store the maximum probabilities of reaching each node from the starting node.
        vector<double> dist(n, 0.0);

//Set the distance of the starting node to 1.0 (indicating certainty) and the distances of all other nodes to 0.0 (indicating uncertainty).
        dist[start] = 1.0;

        queue<int> q;

        q.push(start);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto it : adj[curr]){
                int neighbour = it.first;
                double prob = it.second;

                double newProb = dist[curr] * prob;

                if(dist[neighbour] < newProb){
                    dist[neighbour] = newProb;
                    q.push(neighbour);
                }
            }
        }

        return dist[end];
    }
};