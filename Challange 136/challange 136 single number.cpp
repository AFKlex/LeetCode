#include<iostream>
#include<vector>
#include<map>
#include <algorithm>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {

        std::map<int,int> mapping;
        
        for(int i=0; i<nums.size(); i++){
            std::cout << "Mapping Count: " << mapping.count(i) << std::endl;
            if(mapping.count(nums[i])>=1){
                mapping[nums[i]]++; 
            }else {
                mapping[nums[i]]= 1;
            }

        }

        for(auto const& [key, val] : mapping){
            if(val != 2){
                return key;
            }

        }

        return 0;
    }
};

int main (){

    Solution a; 
    std::vector<int> nums = {2,2,1};
    int result = a.singleNumber(nums); 

    std::cout << "Result: " << result << std::endl; 
    return 0; 
}