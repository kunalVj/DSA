class Solution {
public:

// TC = O(log(m*n)), SC = 0(1)
// we treat the given matrix as an array. For any index in our array, we can get its corresponding position of the matrix.
// The row number is given by - array index / total no of columns, while the column number is given by - array index % total no of columns.


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row * col - 1;

        int mid;
        int element;

        while(start <= end){
            mid = start + (end - start)/2;
            element = matrix[mid/col][mid%col];

            if(target == element){
                return true;
            }
            
            else if(target < element){
                end = mid - 1;
            }

            else{
                start = mid + 1;
            }
        }

        return false;
        
    }
};


/*Linear search
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == target){
                    return true;;
                }
            }
        }
        return false;*/