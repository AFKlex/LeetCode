#include<iostream>
#include<vector>

class Solution {
public:
   int search(std::vector<int>& nums, int target) {
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

    std::cout << "smallest is at: " << left<<std::endl;

    if (nums[left] == target){
        return left; 
    }

    if(nums[0] > target || left == 0){
        right = nums.size()-1; 
    }else{
        right = left-1; 
        left = 0; 
    }

    std::cout << "New Right: " << right <<std::endl; 
    std::cout << "New Left: " << left <<std::endl; 

    // Binary Search
    while(left <= right){
        int mid = left +(right - left)/2; 

                std::cout << "number at mid " << nums[mid] << std::endl;  
        std::cout << "mid "<< mid << std::endl; 
        std::cout << "left " << left << std::endl; 
        std::cout << "right " << right << "\n"<<std::endl;

        if(nums[mid] == target){
            return mid; 
        }
        
        if(nums[mid] < nums[right]){
            if(nums[mid] < target && target <= nums[right]){
                left = mid +1; 
            }else {
                right = mid -1; 
            }
        }else{
            if(nums[left] < target && target < nums[mid]){
                right = mid -1; 
            }else{
                left = mid +1; 
            }
        }

    }



    return -1;
    //return left;
}
};

int main(){

    std::vector<int> nums = {3,5,1};
    int target = 3;
    Solution a; 
    int result = a.search(nums,target); 
    std::cout << "Result " << result << std::endl; 
    return 0; 
}