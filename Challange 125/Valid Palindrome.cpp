#include<iostream>
#include<string>
#include<algorithm>

class Solution {
public:
    bool isPalindrome(std::string s) {

        s = sanitizeString(s); 
        //std::cout << s << std::endl; 

        std::string::iterator p1 = s.begin();
        std::string::iterator p2 = s.end()-1;

        // std::cout << s.size() << std::endl; 
        // if(s.size()<2){ // Special case if string is 2 char long 
        //         return false; 
        // }


        while (p1 < p2){
            if (*p1 != *p2){
                //  std::cout << *p1 << std::endl; 
                //  std::cout << *p2 << std::endl;  
                //std::cout << "False" << std::endl; 
                return false; 
            }
            p1++; 
            p2--; 
        }
        return true;
        
    }

    std::string sanitizeString(std::string input){
        std::string result; 
        for(int i=0; i<input.size(); i++){
            input[i] = tolower(input[i]);
            if (isValidElement(input[i])){
                result.push_back(input[i]);
            }
        }
        return result; 

    }

    bool isValidElement(char c){
        //int temp = c; 
        //std::cout << "Value of " << c << " is: "<< temp << std::endl; 

        if ((c >= 97 && c <= 122)|| (c >= 48 && c<= 57)){
            return true; 
        }else{
            return false;
        }

    }

};


int main (){

    Solution a; 
    std::string input = "0P";

    bool result = a.isPalindrome(input);
    std::cout << "Input is a palindrome: " << result << std::endl; 
    return 0; 
}