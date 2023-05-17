class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nrow = x + dx[k];
                int ncol = y + dy[k];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == -1){
                    q.push({nrow,ncol});
                    ans[nrow][ncol] = ans[x][y] + 1;
                }
            }
        }

        return ans;
    }
};