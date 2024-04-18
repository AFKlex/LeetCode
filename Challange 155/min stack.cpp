/*
This solution does work however in the worst case this has no O(1) runtime to remove element. 
*/

#include<iostream>
#include<vector>

class MinStack {
      std::vector<int> stack; 
      int smallestElement= INT32_MAX ; 
public:
    MinStack() {
        
    }
    
    void push(int val) {
        this->stack.push_back(val); 
        if(smallestElement > val){
            smallestElement = val;
        }
    }
    
    void pop() {
        if(smallestElement == top()){
            smallestElement = INT32_MAX;
            for(int i=0; i< this->stack.size()-1;i++){
                if(smallestElement > this->stack[i]){
                    smallestElement = this->stack[i];
                    if(smallestElement == top()){
                        break; 
                    } 
                }
            }

        }
        this->stack.pop_back();
    }
    
    int top() {
        if(!this->stack.empty()){
            return this->stack.back();
        }
        else {
            return 0;
        }
        
    }
    
    int getMin() {
        return smallestElement;
    }

    void printStack(){
        std::cout << "Bottom of Stack: "<< std::endl; 
        for(int i= 0; i<this->stack.size(); i++){
            
            std::cout << this->stack[i] << std::endl; 

        }
        std::cout << "Top of Stack" << std::endl;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main (){
    
    MinStack* obj = new MinStack(); 
    obj->push(1); 
    obj->push(2); 
    obj->push(3); 
    obj->push(4);
    obj->push(0);
    obj->pop();
    int smallest = obj->getMin();
    int top = obj->top();
    
    obj->printStack();
    std::cout << "Top of Stack: " << top << std::endl;
    std::cout << "Smallest Element: " << smallest << std::endl;

    return 0; 
}