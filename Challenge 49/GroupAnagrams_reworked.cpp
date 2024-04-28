#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>

class helper{
    public: 
    static void printVector(std::vector<std::string> inputVector){

        for(int i=0; i<inputVector.size();i++){
            std::cout << inputVector[i] <<" "; 
        }
        std::cout << std::endl; 

    }

    static void printVectorOfVectors(std::vector<std::vector<std::string>> inputVector){

        for(int i=0;i<inputVector.size();i++){
            printVector(inputVector[i]);
        }
        std::cout << std::endl; 

    }
    
};

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    
    //helper::printVector(original_values);
        std::unordered_map<std::string, std::vector<std::string>> anagramGroups;


    // Iterate through each string
    for (const std::string& str : strs) {
        // Sort the characters of the string
        std::string sortedStr = str;
        std::sort(sortedStr.begin(), sortedStr.end());
        
        // Add the sorted string to the hashmap
        // Strings with the same sorted form will map to the same key
        anagramGroups[sortedStr].push_back(str);
    }
    
    std::vector<std::vector<std::string>> result;
    
    // Copy values from hashmap to result vector
    for (auto it = anagramGroups.begin(); it != anagramGroups.end(); ++it) {
        result.push_back(it->second);
    }
    
    return result;

    }
};



int main (){

    Solution a; 
    std::vector <std::string> input = {"eat","tea","tan","ate","nat","bat"}; 

    
    std::vector<std::vector<std::string>> result = a.groupAnagrams(input); 
    helper::printVectorOfVectors(result);
    return 0; 
}