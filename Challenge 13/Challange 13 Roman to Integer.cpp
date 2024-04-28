#include<iostream>
#include<string>
#include<map>
#include <vector>

class Solution {
public:
    std::vector<int> getIndex(std::string str, std::string s)
{

    std::vector<int> indexes;  

    bool flag = false;
    for (int i = 0; i < str.length(); i++) {
        if (str.substr(i, s.length()) == s) {
            //std::cout << i << " ";
            indexes.push_back(i);
            flag = true;
        }
    }
  
    return indexes; 
}
    

    int romanToInt(std::string s) {

        std::map<std::string, int> roman_values;
        
        roman_values["I"] = 1; 
        roman_values["V"] = 5;
        roman_values["X"] = 10;
        roman_values["L"] = 50;
        roman_values["C"] = 100; 
        roman_values["D"] = 500;
        roman_values["M"] = 1000;

        roman_values["IX"] = 9;
        roman_values["IV"] = 4;

        roman_values["XC"] = 90;
        roman_values["XL"] = 40;

        roman_values["CM"] = 900;
        roman_values["CD"] = 400;
        

        std::string checks[] = {"CD","CM", "XL", "XC", "IV", "IX"};
        int check_length = 6; 

        std::vector<int> indexes;
        std::string to_check;

        int result_sum = 0; 

        for (int j = 0; j < check_length; j++){
            
            to_check = checks[j]; 
            indexes.clear();
            indexes= getIndex(s,to_check);

            std::cout << "To Check" << to_check << "J: " << j<<std::endl; 

            if(indexes.size() ==0 && j == check_length){
                break;
            }
            else if(indexes.size() ==0 ){
                continue;
            }
            else if(s.size() < 2){
                break;
            }
            


            for(int i =indexes.size()-1; i>=0 ;i--){
            
                s = s.erase(indexes[i],to_check.size());
                result_sum += roman_values[to_check];
                std::cout << " Index at: " << indexes[i]<< " String: " << s <<"\n" << std::endl;

            }



        }

        
        


        for (int i = 0; i < s.size(); i++){

            std::string current_value(1,s[i]);

            //std::cout << roman_values[current_value] << std::endl; 

            result_sum = result_sum + roman_values[current_value];


        }
        return result_sum; 
    }
};

int main(){

    Solution a; 
    int result = a.romanToInt("III");
    std::cout <<"The Reuslt is: " << result << std::endl;  


    return 0; 

}
