// If matrix[row][col] == target: We have found the target and so we will return true.
// If matrix[row][col] > target: We need the smaller elements to reach the target. But the column is in increasing order and so it contains only greater elements. So, we will eliminate the column by decreasing the current column value by 1(i.e. col–) and thus we will move row-wise.
// If matrix[row][col] < target: In this case, We need the bigger elements to reach the target. But the row is in decreasing order and so it contains only smaller elements. So, we will eliminate the row by increasing the current row value by 1(i.e. row++) and thus we will move column-wise.
// T.c:-O(N+M)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();  
        int n=matrix[0].size();
        int r=0;
        int c=n-1;   //we can start searching from top,right or left,bottom bcz at
        //that points there is a sorted list which start from row and goes from column
        while(r<m && c>=0){
            if(matrix[r][c]==target)  return true;
            else if(matrix[r][c] > target) c--;
            else r++;
        }
        return false;
    }
};