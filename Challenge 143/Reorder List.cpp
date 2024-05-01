#include<iostream>
#include<vector>


struct ListNode {
     int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    void reorderList(ListNode* head) {
        
        ListNode* fast= head; 
        ListNode* slow= head;
        // Find mid element 
        if(fast->next == nullptr || fast->next->next == nullptr){

            return ;

        }
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next; 
            slow = slow->next;
        } 
        std::cout << "Mid value is: " << slow->val << std::endl; 
        
        // Split into two list
        ListNode* first= head; 
        ListNode* second= slow->next;
        slow->next = nullptr; 

        printList(first); 
        printList(second);
        // Reverse second list 
        second = reverseLinkedList(second); 
        printList(second);

        // Merge two list 
        merge(first, second); 
        printList(first); 
        

    }

    ListNode* merge(ListNode* first, ListNode* second){

        ListNode* firstNext = first->next; 
        ListNode* secondNext = second->next;
        while(firstNext != nullptr && secondNext !=nullptr){

            first->next = second;
            second->next = firstNext;
            
            std::cout << "Second" << second->val << std::endl;
            
            first = firstNext; 
            firstNext = firstNext->next; 
            second = secondNext; 
            secondNext = secondNext->next;
        }
        

        if(firstNext == nullptr && secondNext == nullptr){
            first->next = second;
            return first;
        }
        if(secondNext ==nullptr){
            std::cout << "Value: "<< second->val << std::endl;
            first->next = second;
            second->next =firstNext; 
        }


        return first;

    }

    ListNode* reverseLinkedList(ListNode * head){

        ListNode* cur = head; 
        ListNode* prev = nullptr; 
        ListNode* next = head->next; 

        while(cur !=nullptr){
            
            next = cur->next;
            cur->next = prev; 
            prev = cur; 
            cur = next;

        }
        return prev;

    }

    void printList(ListNode * head){
        while(head != nullptr){
            std::cout << head->val << " ";
            head = head->next; 
        }
        std::cout << std::endl;
    }
};


int  main(){
    
    ListNode a(1),b(2),c(3),d(4),e(5); 
    a.next = &b; 
    b.next = &c; 
    c.next = &d; 
    d.next = &e;

    Solution s;
    s.reorderList(&a);  
    return 0; 
}