class Solution {
public:
// intutuion = we se if water can go from ocean to land, and if current coordinate is greater than it's neighbouring
// coordinates then water can not flow to them
// only water can flow to those neighbours who are greater than current coordinate
// take 2 grids for both pacific and atlantic ocean and check in which island water flow and mark them visited and push into queue
// after doing for both oceans now store the answer in ans vector, if a same coordinate is marked visited
// in both pacific and atlantic grid then it means from that coordinate water can flow to both oceans

void bfs(vector<vector<int>>& heights, queue<pair<int,int>> &q, vector<vector<int>> &vis){
    int n = heights.size();
    int m = heights[0].size();

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++){
            int nrow = x + dx[k];
            int ncol = y + dy[k];

//along with all the eligibility criteria the next coordinates height must be greater than or equal to 
// the current coordinates heights cause we are moving from ocean to island and
//we want the water to go from island to ocean.
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && heights[nrow][ncol] >= heights[x][y] && 
            !vis[nrow][ncol]){
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        queue<pair<int, int>> pac;
        queue<pair<int,int>> atl;

//push the respective boundary elements to the pacific and atlantic queue and visited array
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    pac.push({i,j});
                    pacific[i][j] = 1;
                }

                if(i == n-1 || j == m-1){
                    atl.push({i,j});
                    atlantic[i][j] = 1;
                }
            }
        }

        vector<vector<int>> ans; // to store final answer

        bfs(heights, pac, pacific);
        bfs(heights, atl, atlantic);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

return ans;

    }
};