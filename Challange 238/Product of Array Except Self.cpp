#include<iostream>
#include<vector>
#include<numeric>
class helper{
    public:
    template<typename t> 
    static void printVector(std::vector<t> input){

        for(const auto &element:input){
            std::cout << element << " "; 
        }

        std::cout << std::endl; 

    }
};

class Solution {
    /*
    The idea behind this algorithm is to first calculate each element before i and store it in an vector. 
    After that calculate each product iterate in reverse order through the array and position multiply the results with the prefix. 
    
    */

public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {

        std::vector <int> productExceptSelf={1}; 

        

        int suffix=1; 
        int prefix=1; 
        
        for(int i= 1; i< nums.size(); i++){
            
            // First add left part of each product to the array:
            prefix *= nums[i-1];  

            std::cout << "prefix "<< prefix <<"\n" <<std::endl;

            productExceptSelf.push_back(prefix);
            
        }

        //helper::printVector(productExceptSelf);
        
        for(int i= nums.size()-1; i>0; i--){
            
            // Now add right part to the array:
            suffix *= nums[i];
            std::cout << "suffix "<< suffix  <<std::endl;
            productExceptSelf[i-1] *= suffix;
        
            
        }

        
        



/*
        for(int i = 0; i<nums.size();i++){ // Simple Solution but the runtime is not right. 
            suffix = 1;
            prefix =1;
            for(int j =0; j<i;j++){
                prefix *=nums[j];
            }

            for(int j =i+1; j<nums.size();j++){
                suffix *=nums[j];
            }

            //std::cout << "Prefix =" << prefix << " Suffix =" << suffix << std::endl; 

            productExceptSelf.push_back(prefix*suffix);
            

        }
*/

        return productExceptSelf; 
    }
};

int main(){

    std::vector<int> input = {1,2,3,4};
    Solution a; 
    std::vector<int> result = a.productExceptSelf(input);

    helper::printVector(result);
    
    return 0; 

}

