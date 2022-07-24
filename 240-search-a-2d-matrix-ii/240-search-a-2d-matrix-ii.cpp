class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = row ? matrix[0].size() : 0;
    int start = 0, end = row, mid, endRow, startRow;
    // first we determine the first row the target might occurs.
    // notice that here we implement the lower_bound binary search.
    while (start < end) {
        mid = (start + end) / 2;
        if (matrix[mid][col-1] >= target) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    startRow = start;
    //then we caclulate the end row (not included) the target might occurs
    // here is for upper_bound binary search.
    start = 0, end = row;
    while (start < end) {
        mid = (start + end) / 2;
        if (matrix[mid][0] > target) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    endRow = start;
    //finally, iterate through each row until we find the target
    // and here is also lower_bound binary search.
    for (int i = startRow;i < endRow;++i) {
        start = 0, end = col;
        while (start < end) {
            mid = (start + end) / 2;
            if (matrix[i][mid] >= target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        if (start < col && matrix[i][start] == target)
            return true;
    }
    return false;
}
};