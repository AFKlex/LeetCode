#include<iostream>
#include<vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        // Check for edge cases
        if (matrix.empty() || matrix[0].empty()) {
            return false; // Matrix is empty
        }

        // Handle matrix with one column
        if (matrix[0].size() == 1) {
            for (const auto& row : matrix) {
                if (row[0] == target) {
                    return true;
                }
            }
            return false;
        }

        // Check if target falls within the range of the matrix
        if (target < matrix[0][0] || target > matrix.back().back()) {
            return false; // Target is out of range of the matrix
        }

        // Find the correct row
        int left = 0;
        int right = matrix.size() - 1;
        int target_row = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] < target) {
                if (mid == matrix.size() - 1 || matrix[mid + 1][0] > target) {
                    target_row = mid;
                    break;
                }
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Perform binary search within the target row
        left = 0;
        right = matrix[target_row].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[target_row][mid] == target) {
                return true;
            } else if (matrix[target_row][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};



int main (){

    std::vector<std::vector<int>> matrix = {{1}};//{{1,3,5,7},{10,11,16,20},{23,30,34,60}}; 
    int target = 2; 

    Solution a; 
    bool result = a.searchMatrix(matrix,target); 
    std::cout << "The result is: "<< result << std::endl; 


    return 0; 
}