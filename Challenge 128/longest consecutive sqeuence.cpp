#include<vector>
#include<iostream>
#include<unordered_set>


class helper{
    public:
    template<typename a>
    static void printUnorderedSet(std::unordered_set <a> elements){

        for(const auto &entry:elements){
            std::cout << " " << entry  << std::endl; 
        }
    }

};

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {

        if(nums.size()<=0){
            return 0;
        }
        
       std::unordered_set <int> nextElements ={nums.begin(), nums.end()}; 
        int highestSequence = 1; 
        for(const auto &entry : nextElements){
            int tempSequence=1;
            if(nextElements.find(entry-1) != nextElements.end()){ 
                continue; // Element is not the start of a sequence 
            }
            
            while(nextElements.find(entry+tempSequence) != nextElements.end()){
                tempSequence++;
                if(tempSequence > highestSequence){
                    highestSequence = tempSequence; 
                }
            }
        }
        return highestSequence;
    }
};

int main (){

    Solution a; 
    std::vector<int> nums = {0,0};

    int result = a.longestConsecutive(nums);
    std::cout << "The longest consecutive sequence is: " << result << std::endl; 
    return 0; 
}