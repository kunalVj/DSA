class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size();
        int col = maze[0].size();

        int dx[] = {-1, 0, 1, 0};  // to move in all 4 direction
        int dy[] = {0, 1, 0, -1};

        int Er = entrance[0];
        int Ec = entrance[1];

        queue<pair<pair<int, int>, int>> q;
        q.push({{Er, Ec}, 0}); // push the entrance and distance
        maze[Er][Ec] = '+';   // to mark the node as visited mark it '+'

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int count = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){ // move in all the direction
                int nrow = r + dx[i];
                int ncol = c + dy[i];

// check if it's valid move
          if(nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && maze[nrow][ncol] == '.'){
              //check if we reached the exit or boundary 
                    if(nrow == row - 1 || nrow == 0 || ncol == col - 1 || ncol == 0){
                        if(nrow != Er || ncol != Ec){ // check if it's entrance cell or not because we can't exit from entrance
                            return count+1;  // if all conditions are satisfied we return distance by incrementing
                        }
                    }

                    q.push({{nrow, ncol}, count+1}); // if that node is not exit then we push it int queue and increment the distance
                    maze[nrow][ncol] = '+';  // and mark it as visited so we don't process it again
                }
            }
        }
        return -1;  // if exit doesn't exist then return -1
    }
};