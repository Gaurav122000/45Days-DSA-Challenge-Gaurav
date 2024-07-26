class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();
        int m = matrix[0].size();

        //we need to traverse the 2d array metrix 
        int row_start = 0, row_end = n-1, column_start = 0, column_end = m-1;

        while(row_start<=row_end && column_start<=column_end){
        // for row_start
        for(int col=column_start; col<=column_end; col++ ){
            result.push_back(matrix[row_start][col]);
        }
        row_start++;

        //for column-end
        for(int row=row_start; row<=row_end; row++){
            result.push_back(matrix[row][column_end]);
        }
        column_end--;

        // for row_end
        if (row_start <= row_end) { // Check if there's a valid row
                for (int col = column_end; col >= column_start; col--) {
                    result.push_back(matrix[row_end][col]);
                }
                row_end--;
        }

        //for column-start
        if (column_start <= column_end) { // Check if there's a valid column
                for (int row = row_end; row >= row_start; row--) {
                    result.push_back(matrix[row][column_start]);
                }
                column_start++;
        }
        }           
        return result;
    }
};//time complexity = O(m*n);
//space complexity = O(1);