#include<iostream>
#include<string>
#include<set>



class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Same error again i did not use a sliding window approach just go through .... 
        /*
        Valid Values are: 
        Symbols 32 - 126
        */ 
       int maxLength = 0; 
       std::string::iterator pl = s.begin()-1;

       std::set<char> substring;  

       for(auto pr=s.begin(); pr < s.end(); pr++){
            

           if(substring.find(*pr)!= substring.end()){
                do{
                    pl++;
                    substring.erase(*pl); 
                }
                while(*pl != *pr);
                substring.insert(*pr);

           } else{
                substring.insert(*pr); 

           }
        int currentDistance = std::distance(pl,pr); 
        //std::cout << "Current Distance: " << currentDistance << std::endl; 
           if(currentDistance> maxLength){
            maxLength =currentDistance;
           }

       }



      return maxLength;   
    }

    

};

int main (){
    Solution a; 
    std::string input = "abcabcbb"; 
    
    int result = a.lengthOfLongestSubstring(input);

    std::cout << "The result is: " << result << std::endl;
    return 0; 
}