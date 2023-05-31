class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n , 0);
        queue<int> q;

        q.push(0); // room 0 will always be open so push it into queue

        while(!q.empty()){
            int room = q.front();
            q.pop();
            vis[room] = 1;

            for(auto key : rooms[room]){
                if(vis[key] == 0){   // if room not visited push it's key in queue
                    q.push(key);
                }
            }
        }

        for(int i = 0; i < n; i++){  // if any room is not visited then return false
            if(!vis[i]){
                return false;
            }
        }

        return true;
    }
};
// tc = O(N+E), N = no. of rooms, E = no.of keys
// sc = O(N)