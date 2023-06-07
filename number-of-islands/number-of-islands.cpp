class Solution {
public:
// to find the no. of islands we traverse the matrix and when we find 1 (land) we increase the count because we found 1 and it confirm that there's atleast 1 island in matrix
// after increasing the count we check it's adjacent elements that if they are also 1 that are connected to it
// when the adjacent element is also 1 we convert it to 0 to mark it as visited so the the connected components will become 0 from 1 and now we check for other islands
// also when we find the 0 (water) we return.
void dfs(int i, int j, int n, int m, vector<vector<char>>& grid){
    if(i < 0 || i >=n || j < 0 || j >= m || grid[i][j] != '1'){   
        return;
    }
    grid[i][j] = '0';       // converting 1 to 0 ro mark it as visited

// checking for adjacent elements

    dfs(i + 1, j, n, m, grid);
    dfs(i - 1, j, n, m, grid);
    dfs(i, j + 1, n, m, grid);
    dfs(i, j - 1, n, m, grid);
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        return count;
    }
};