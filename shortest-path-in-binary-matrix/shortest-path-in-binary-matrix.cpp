class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int n = grid.size();

       if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
           return -1;
       }
        queue<pair<pair<int,int>, int>> q;
        q.push({{0, 0}, 1}); // push the index and path length
        grid[0][0] = 1; // when a element is pushed into queue mark it as visited with 1

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int length = q.front().second;
            q.pop();

            if(x == n - 1 && y == n - 1){    // if reached last index then return the length
                return length;
            }
            // check for all 8 directions
           int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
            int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

            for(int i = 0; i < 8; i++){ 
                int nrow = x + dx[i];
                int ncol = y + dy[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0){
                q.push({{nrow, ncol}, length + 1});
                grid[nrow][ncol] = 1;
                }
            }
        }

        return -1;
    }
};