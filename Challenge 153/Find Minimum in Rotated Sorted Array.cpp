#include<iostream>
#include<vector>

class Solution {
public:
   int findMin(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } 
        else if (nums[mid] < nums[right]) {
            right = mid;
        } 
        else {
            right--;
        }
    }

    return nums[left];
}
};

int main(){

    std::vector<int> nums = {3,4,5,6,1,2};

    Solution a; 
    int result = a.findMin(nums); 
    std::cout << "Result " << result << std::endl; 
    return 0; 
}