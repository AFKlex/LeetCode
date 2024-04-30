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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
        // printList(list1);
        // std::cout <<std::endl; 
        // printList(list2);
        ListNode* new_list= NULL; 
        ListNode* list1_cur = list1; 
        ListNode* list2_cur = list2; 
        ListNode* prev = new ListNode(0); 
        ListNode* start = prev; 
        while(list1_cur!=nullptr && list2_cur!=nullptr){
            
            if(list1_cur->val < list2_cur->val){
                prev->next = list1_cur; 
                list1_cur = list1_cur->next; 
            }else{
                prev->next = list2_cur; 
                list2_cur = list2_cur->next; 
            }
            prev = prev->next; 
            //printList(prev);
        }

        if(list1_cur ==nullptr){
                prev->next = list2_cur; 
                
        }else if(list2_cur == nullptr){
                prev->next = list1_cur; 
        }
        //printList(start->next);
        return start->next; 
    }

    void printList(ListNode* list1) {
    
        while(list1 != nullptr){

            std::cout << list1->val << " "; 
            list1 = list1->next; 
        }
        std::cout << std::endl; 


    }
};


int main(){

    ListNode ListA_1(1),ListA_2(2),ListA_3(4);
    ListA_1.next = &ListA_2; 
    ListA_2.next = &ListA_3;  
    ListNode ListB_1(1),ListB_2(3),ListB_3(4); 
    ListB_1.next = &ListB_2; 
    ListB_2.next = &ListB_3;

    Solution s; 
    s.mergeTwoLists(&ListA_1,&ListB_1);


    return 0; 
}