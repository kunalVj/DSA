class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        int area = 0;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
         for(int i = 0; i < n; i++){
             for(int j = 0 ; j < m; j++){
                 if(grid[i][j] == 1){
                     int ans = 1;
                     grid[i][j] = 0;
                     q.push({i,j});

                     while(!q.empty()){
                     int x = q.front().first;
                     int y = q.front().second;
                     q.pop();

                     for(int k = 0; k < 4; k++){
                         int nrow = x + dx[k];
                         int ncol = y + dy[k];

                         if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1){
                             ans++;
                             grid[nrow][ncol] = 0;
                             q.push({nrow,ncol});
                         }
                     }
                  }

                  area = max(area, ans);

              }
          }
      }

     return area;
    }
};