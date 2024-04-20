#include<iostream>
#include<vector>
#include "/home/afklex/Documents/04_Programmieren/LeetCode/Helper/helper.h"
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {

    std::vector<int>::iterator p1 = numbers.begin();
    std::vector<int>::iterator p2 = numbers.end()-1; 

    while(p1<p2){
            int tempSum= *p1 + *p2; 
            if( tempSum == target){
                int index_1 = std::distance(numbers.begin(),p1); 
                int index_2 = std::distance(numbers.begin(),p2); 
                index_1++; index_2++;
                return {index_1, index_2};
            } else if(tempSum > target){
                p2--;
            }else{
                p1++;
            }
         
        }
         
    return {}; 
    }
};

int main(){
    
    Solution a; 
    std::vector<int> input  = {2,7,11,15};
    int target = 9; 
    helper::printVector(input);
     
    std::vector<int> result = a.twoSum(input,target);
    helper::printVector(result); 
    
    return 0; 
}