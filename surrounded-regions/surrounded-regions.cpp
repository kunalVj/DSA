class Solution {
public:
void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis, int dx[], int dy[]){
    vis[row][col] = 1;     // visit

    int n = board.size();
    int m = board[0].size();

    for(int i = 0; i < 4; i++){     // move to all 4 direction
        int nrow = row + dx[i];
        int ncol = col + dy[i];

// check if valid or not 
        if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
            dfs(nrow, ncol, board, vis, dx, dy);
        }
    }

}
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int dx[] = {-1, 0, 1, 0};  // for moving in all 4 dir
        int dy[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

// check on boundary, if 'O' found than it's not surrounded by X we mark it visited in visited array

// checking on row
        for(int j = 0; j < m; j++){ // row will be constant unlike col

// checking for first row
            if(!vis[0][j] && board[0][j] == 'O'){  
               dfs(0, j, board, vis, dx, dy);
            }

// checking for last row
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                
                dfs(n-1, j, board, vis, dx, dy);
            }
        }

        for(int i = 0; i < n; i++){  // col will be constant unlike row

        // checking on first col 
            if(!vis[i][0] && board[i][0] == 'O'){
    
                dfs(i, 0, board, vis, dx, dy);
            }

// checking on last col 
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                
                dfs(i, m-1, board, vis, dx, dy);
            }
        }

// traverse again and now replace the surrounded O with X (whic are inside boundary and are not connected with boundary O)
        for(int i = 0; i < n; i++){      
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

// T.C -> O(n*m*4) + O(n)
// S.C -> O(n*m) +  O(n*m) -> O(n*m)
