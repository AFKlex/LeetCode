#include<iostream>
#include<vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {

    /*
    This is floyds cycle detection a problem that i would not be able to solve without knowing that. 
    */

   // Find intersection 
   int slow = nums[0];
   int fast = nums[0];
   int intersection =0;  
   for(int i=0; i<nums.size(); i++){
        
        slow = nums[slow]; 
        fast = nums[nums[fast]]; 

        std::cout << "Fast " << fast << std::endl; 
        std::cout << "slow " << slow << "\n"<< std::endl; 
        

        if(nums[slow] == nums[fast]){
            //intersection = slow;  
            break;
        }

   }
     std::cout <<"Intersection is at: " << slow << std::endl; 
    int finder = nums[0]; 
    for(int i=0; i<nums.size()+10; i++){
        
        std::cout << "finder " << finder << std::endl; 
        std::cout << "slow " << slow << "\n"<< std::endl; 
        
          
        if(finder == slow){
            return finder; 
        }

        finder = nums[finder]; 
        slow = nums[slow];
        

    }

    return 0; 

    }

       
};

int main(){

    std::vector<int> nums = {3,1,3,4,2};
    Solution s; 
    int result = s.findDuplicate(nums); 
    std::cout << "The result is: " << result << std::endl;

    return 0; 
}