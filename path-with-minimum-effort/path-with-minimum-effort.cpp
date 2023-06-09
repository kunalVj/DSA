class Solution {
public:
// we need to minimum effort of all the path
// take the max efforts of every path and from them return the minimum effort
// for eg- in eg 1 we start from (0,0) i.e 1 and go to (0,1) i.e 2 with the difference b/w them as 1
// now moving to (0,2) the difference will be 0 b/w (0,1) and (0,2) and we need the maximum effort for this path
// so we won't update the diff to 0 it will be 1 only and we keep repeating it, when we get greater effort from previous we update
// we use priority queue(min heap) because we want min effort and in this we store ({difference, {row,col}})
// row = n - 1 and col = m - 1 is present in queue that will be our answer as the it will be present
// at top with minimum effort. in min heap our destination with min. effort will be on top only
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

// Create a priority queue containing pairs of cells 
// and their respective distance from the source cell in the 
// form {diff, {row of cell, col of cell}}.
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
         // Create a diffrence matrix with initially all the cells marked as
        // unvisited and infinity and the diff for source cell (0,0) as 0.
        vector<vector<int>> diff(n, vector<int>(m, 1e9));
        diff[0][0] = 0;

        pq.push({0, {0, 0}});

// Iterate through the matrix by popping the elements out of the queue
// and pushing whenever a shorter distance to a cell is found.
        while(!pq.empty()){
            int effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

// Check if we have reached the destination cell,
// return the current value of difference (which will be min).
            if(x == n-1 && y == m-1){
                return effort;
            }

            int dx[] = {-1, 0, 1, 0};   // to move in all 4 direction
            int dy[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int nrow = x + dx[i];
                int ncol = y + dy[i];

         if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){ // check if the cell is valid
         // Effort can be calculated as the max value of differences 
        // between the heights of the node and its adjacent nodes.
                   int newEffort = max(abs(heights[x][y] - heights[nrow][ncol]), effort);
                   
                   // If the calculated new effort is less than the prev value
                  // we update as we need the min effort.
                   if(newEffort < diff[nrow][ncol]){
                       diff[nrow][ncol] = newEffort;

                        pq.push({newEffort, {nrow, ncol}});
                   }
                }
            }
        }

        return 0; 
    }
};