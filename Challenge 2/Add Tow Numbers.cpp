#include<iostream>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
  
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0; 
    ListNode* start = new ListNode(0); // Initialize with a dummy node
    ListNode* cur = start;
    
    while (l1 != nullptr || l2 != nullptr || carry == 1) {
        int a = (l1 != nullptr) ? l1->val : 0;
        int b = (l2 != nullptr) ? l2->val : 0;
        int sum = a + b + carry;
        
        carry = sum / 10; // Calculate carry for next iteration
        int digit = sum % 10; // Calculate digit to be stored in current node
        
        cur->next = new ListNode(digit); // Create a new node
        cur = cur->next; // Move to the next node
        
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }
    
    return start->next; // Skip the dummy node and return the actual result
}


    void printLinkedList(ListNode* head){

        while(head !=nullptr){
            std::cout << head->val << " "; 
            head = head->next; 
        }

        std::cout << std::endl; 
        
    }


    // ListNode* reverseLinkedList(ListNode* head){

    //     ListNode* cur = head; 
    //     ListNode* prev= nullptr; 
    //     ListNode* next = head->next; 

    //     while (cur !=nullptr){

    //         next = cur->next;
    //         cur->next = prev; 
    //         prev = cur;
    //         cur = next; 
            

    //     }
    //     return prev; 
    // }
};

int main(){

    ListNode a(2),b(4),c(3); 
    a.next = &b; 
    b.next = &c; 

    ListNode d(5),e(6),f(4);
    d.next = &e; 
    e.next = &f; 


    Solution s; 
    s.addTwoNumbers(&a, &d);

    return 0; 
}