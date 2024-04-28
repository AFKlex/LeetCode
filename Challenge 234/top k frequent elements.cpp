#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

class helper{
    public:
    void static printVector(std::vector<int> input){

        for(int i= 0; i<input.size() ; i++){

            std::cout << input[i] << " ";
        }
        std::cout << std::endl;
    }
    public:
    void static printMap(std::map<int,int> &hashMap){

        for (const auto& pair : hashMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    
    }


};

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {  
        std::map<int, int> countMap;

    // Count occurrences of each value
    for (const auto& val : nums) {
        countMap[val]++;
    }

    // Sort the map based on count in descending order
    std::vector<std::pair<int, int>> sortedCounts(countMap.begin(), countMap.end());
    std::sort(sortedCounts.begin(), sortedCounts.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                  return a.second > b.second;
              });

    // Extract the top k elements
    std::vector<int> topValues;
    for (int i = 0; i < std::min(k, static_cast<int>(sortedCounts.size())); ++i) {
        topValues.push_back(sortedCounts[i].first);
    }
    
    return topValues;
    }
};

int main(){

    Solution a; 
    std::vector<int> nums = {1,1,1,2,2,3};
    a.topKFrequent(nums,2);
}

