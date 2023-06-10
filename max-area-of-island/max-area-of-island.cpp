class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        int area = 0;    // if we encounter different group of islands we will keep updating the maximum area of encountered islands

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

         for(int i = 0; i < n; i++){      // traverse the grid
             for(int j = 0 ; j < m; j++){
                 if(grid[i][j] == 1){  
                     int ans = 1;        // if we encounter the island start storing it's area in ans, area of 1 island = 1
                     grid[i][j] = 0;    // mark the island as visited by turning 0 so we can't visit it again
                     q.push({i,j});       // push the node to traverse it's adjacent node

                     while(!q.empty()){
                     int x = q.front().first;
                     int y = q.front().second;
                     q.pop();

                     for(int k = 0; k < 4; k++){    // moving in all 4 direction 
                         int nrow = x + dx[k];
                         int ncol = y + dy[k];

                         if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1){ // if node is valid
                             ans++;             // if we find island adjacent to previous we increase the area count
                             grid[nrow][ncol] = 0; // mark it visited
                             q.push({nrow,ncol});   
                         }
                     }
                  }

                  area = max(area, ans);   // if the new area is greater than previous one than update otherwise it will remain same

              }
          }
      }

     return area;
    }
};