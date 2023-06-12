class Solution {
public:

// use the dijkstra algo with some changes :- don't use priority queue and use queue, store the stops first in queue then src and then dist i.e cost
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>>adj[n];
        
        for(auto it : flights){ // create the graph
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src, 0}});     // {stop, {src, cost}}     

        vector<int> dist(n, 1e9);
        dist[src] = 0;       // src distance will be 0

        while(!q.empty()){
            auto i = q.front();
            q.pop();
            int stops = i.first;
            int node = i.second.first;
            int cost = i.second.second;

            if(stops > k) break;       // if stops exceeds k no need to process further 

            for(auto it : adj[node]){    // process the nodes neighbour
                int adjNode = it.first;
                int edgeW = it.second;

                if(cost + edgeW < dist[adjNode] && stops <= k){      // if the new cost is less than existing then update the new one while k <= stops
                    dist[adjNode] = cost + edgeW;
                    q.push({stops + 1, {adjNode, cost + edgeW}});   
                }
            }
        }

        if(dist[dst] == 1e9){     // if we don't reach destination then return -1
            return -1;
        }

        return dist[dst];     // if destination is reached then return the cost

    }
};