#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
          
        std::stack<char> parantheses; 

        for(int i=0; i< s.size();i++){

            char current_parenthese = s[i];
            //std::cout << "Current Kalmmer"<< current_parenthese << std::endl; 

            if (current_parenthese == '{' || current_parenthese == '(' || current_parenthese == '['){
                //std::cout << "Put Paranthese on stack"<< current_parenthese << std::endl; 
                parantheses.push(current_parenthese); 
            }
            else if(current_parenthese == ']' || current_parenthese == '}' || current_parenthese == ')'){

                if (parantheses.size() == 0){
                    return false; 
                }
                // Check if parathese is ontop of stack 
                
                if ((parantheses.top() == '(' && current_parenthese == ')') 
                    || (parantheses.top() == '[' && current_parenthese == ']')
                     ||(parantheses.top() == '{' && current_parenthese == '}') ){
                    //std::cout << "Remove Paranthese from stack"<< current_parenthese << std::endl; 
                    parantheses.pop(); 

                }else{
                    return false; 
                }
            }
            else{
                //std::cout << "Unexpected input in String" << std::endl; 
                return false; 
            }

            //std::cout << "Next loop run \n" << std::endl; 
        }
        
        if (parantheses.size()!=0){
            return false; 
        } else {
            return true; 
        }
    }
};


int main(){

    Solution a; 
    std::cout <<"Is result vaild?:" <<a.isValid("()[]{}") << std::endl;

}