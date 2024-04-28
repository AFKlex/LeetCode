#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include"/home/afklex/Documents/04_Programmieren/LeetCode/Helper/helper.h"

class Solution {
public:
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;

    for (int i = 0; i < nums.size(); ++i) {
        // Skip duplicates of nums[i]
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int target = -nums[i];
        // Early exit if nums[i] is greater than zero
        if (nums[i] > 0) {
            break;
        }

        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k) {
            int sum = nums[j] + nums[k];
            if (sum == target) {
                result.push_back({nums[i], nums[j], nums[k]});
                
                // Skip duplicates of nums[j]
                while (j < k && nums[j] == nums[j + 1]) {
                   ++j;
                }

                // Skip duplicates of nums[k]
                while (j < k && nums[k] == nums[k - 1]) {
                    --k;
                }

                // Move to the next distinct elements
                ++j;
                --k;
            } else if (sum < target) {
                ++j;
            } else {
                --k;
            }
        }
    }

    return result;
}

};

int main (){
    Solution a;
    std::vector<int> nums = {0,0,0,0,0,0}; 
    std::vector<std::vector<int>> result = a.threeSum(nums);
    
    helper::printVectorOfVector(result);

    return 0; 
}