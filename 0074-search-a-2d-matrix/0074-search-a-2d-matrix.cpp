class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        //  checking matrix is empty or not
        if(matrix.empty() || matrix[0].empty()) return false;
        // size of row
        int n = matrix.size();

        // size of columns
        int m = matrix[0].size();

       // search range of target
        int low =0, high = n*m-1;

        while(low <= high){
            // calculate mid

            int mid = low + (high -low)/2;

            // converting mid index to corresponding 2D indices

            int row = mid/m;
            int col = mid%m;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid+1;
            else high = mid -1;
        }
        return false;  
    }
};