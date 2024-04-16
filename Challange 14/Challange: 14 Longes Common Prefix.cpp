#include<iostream>
#include<vector>
#include<string>
#include <algorithm> 

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        
        std::string prefix = ""; 

        if (strs[0].size()<1){
            return prefix;
        }

        int smallest_string_size= strs[0].size(); // Define first element as smalles string size 
        for(int i=1; i<strs.size();i++){ // check against all other elements
            
            if (smallest_string_size > strs[i].size()){
                smallest_string_size = strs[i].size(); // change smallest string size if needed
            }

        }
         

        //std::cout << "Smallest String Size: " << smallest_string_size << std::endl; 


        for(int i=0; i<smallest_string_size;i++){
            
            char current_letter = strs[0][i]; 

            //std::cout << "Current Letter:" << current_letter << std::endl;  

            for(int j=0;j<strs.size();j++){
                
                //std::cout << "Current J:" << j << std::endl;
                //std::cout << "string[i][j]:" << strs[j][i]  << std::endl;
                //std::cout << "Current Letter:" << current_letter << std::endl;
                //std::cout << std::endl;

                if (strs[j][i] != current_letter){
                    return prefix; // return current prefix string
                }

            }
            //std::cout << "Loop ended" << std::endl;

            prefix.push_back(current_letter);// ad to prefix string 



        }
        //std::cout << "Second Loop ended" << std::endl;


        return prefix; 
    }
};

int main (){

    Solution a; 
    std::vector<std::string> a_input = {"flower","flower","flower","flower"};
    std::string a_result = a.longestCommonPrefix(a_input); 
    std::cout << "The Prefix is: " << a_result << std::endl; 

    return 0; 
}

