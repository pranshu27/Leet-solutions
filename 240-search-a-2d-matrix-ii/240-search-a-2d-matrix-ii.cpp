class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up=0;
        int left=0;
        int down=matrix.size()-1;
        int right=matrix[0].size()-1;        
        while(up<=down&&left<=right)
        {
            if(matrix[up][right]==target||matrix[down][left]==target)return true;
            if(matrix[up][right]<target){
                up++;
            }
            else
            {
                right--;
            }
            if(matrix[down][left]<target){
                left++;
            }
            else
            {
                down--;
            }
        }
        return false;
    }
};