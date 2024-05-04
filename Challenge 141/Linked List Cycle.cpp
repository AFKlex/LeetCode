#include<iostream> 
#include<unordered_set>

 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        std::unordered_set<ListNode*> seen; 

        while(head !=nullptr){

            if(seen.find(head)!=seen.end()){
                return true;                 
            }
            seen.insert(head);
            head = head->next; 
        }

        return false;

    }
};


int main (){

    ListNode a(3),b(2),c(0),d(-4); 
    a.next = &b; 
    b.next = &c; 
    c.next = &d; 
    d.next = &b; 


    
    Solution s; 
    bool result = s.hasCycle(&a);
    std::cout <<"The result is: " <<result << std::endl;

    return 0; 
}