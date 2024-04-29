#include<iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };



class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* current_node = head; 
        ListNode* prev_node = nullptr;
        ListNode* next_node= NULL;  // Node we are going to check next 

        while(current_node != NULL){
            next_node = current_node->next; 
            current_node->next = prev_node; 
            prev_node = current_node; 
            current_node = next_node; 
            
        }

        head = prev_node; 



        return head; 
        
    }

    void printList(ListNode* head) {

        while( head != NULL){


            std::cout << head->val << std::endl; 
            head = head->next; 
        }
        std::cout << "\n" << std::endl; 
    }
};



int main (){


    ListNode a(0),b(1),c(2),d(3),e(4),f(5);
    a.next = &b; 
    b.next = &c; 
    c.next = &d; 
    d.next = &e; 
    e.next = &f;  
    

    Solution s; 
    //s.printList(&a); 
    auto erg = s.reverseList(&a);
    s.printList(erg);

    return 0; 
}