class Solution {
public:
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

        vector<vector<int>> ans;

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