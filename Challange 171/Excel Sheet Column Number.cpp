#include<iostream>
#include <algorithm>
#include<string>
#include<map>
#include<cmath>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        std::reverse(columnTitle.begin(),columnTitle.end());  // Reverse string because otherwise the order of the elements is not fitting
        int column_number=0;
        std::map<char,int> values; 
        values['A'] = 1; 
        values['B'] = 2; 
        values['C'] = 3;
        values['D'] = 4;
        values['E'] = 5;
        values['F'] = 6;
        values['G'] = 7;
        values['H'] = 8;
        values['I'] = 9;
        values['J'] = 10;
        values['K'] = 11;
        values['L'] = 12;
        values['M'] = 13;
        values['N'] = 14;
        values['O'] = 15;
        values['P'] = 16;
        values['Q'] = 17;
        values['R'] = 18;
        values['S'] = 19;
        values['T'] = 20;
        values['U'] = 21;
        values['V'] = 22;
        values['W'] = 23;
        values['X'] = 24;
        values['Y'] = 25;
        values['Z'] = 26;

        
        for(int i=0; i<columnTitle.size(); i++){
            int char_value = values[columnTitle[i]];
            std::cout << "Char Value of: " << columnTitle[i] << " is the value " <<char_value <<std::endl; 
            column_number += char_value * pow(26,i); 

            

        }


        return column_number; 
        
    }
};

int main(){

    Solution a; 
    int result; 

    std::string input; 

    std::cout << "Pleas provide input: ";
    std::cin >> input;

    result = a.titleToNumber(input);
    
    std::cout << "The result is: " << result << std::endl; 



}