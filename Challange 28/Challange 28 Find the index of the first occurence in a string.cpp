#include<iostream>
#include<string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {

       return haystack.find(needle); 
        
    }
};

int main(){


    Solution a; 
    int index = a.strStr("leetcode", "leeto");

    std::cout << "Result found at: " << index << std::endl;  
    return 0;
}