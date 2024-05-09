#include<iostream>
#include<vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return -1; // Handle empty vector case
    if (n == 1) return nums[0] == target ? 0 : -1; // Handle single element vector case
    
    int l = 0; 
    int r = n - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) {
            return m; 
        }
        if (nums[m] < nums[r]) { // Right half is sorted
            if (nums[m] < target && target <= nums[r]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        } else { // Left half is sorted
            if (nums[l] <= target && target < nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    return -1; // Target not found
}



};

int main (){

    std::vector<int> nums = {5};
    int target = -5; 

    Solution s; 
    int result = s.search(nums,target);

    std::cout << "Result is: " << result << std::endl; 

    return 0; 
}