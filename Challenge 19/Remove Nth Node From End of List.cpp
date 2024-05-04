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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode * start = head; 

        if(head->next == nullptr){
            return nullptr;
        }else if(head->next->next == nullptr){
            if(n==1){
            head->next = nullptr; 
            return head; 
            }else{
                return head->next; 
            }
        }
        int array_Size =n+1;
        ListNode * lastElements[array_Size]; 
        int count = 0; 
        while(head !=nullptr){
            lastElements[count%array_Size] = head; 
            count++; 
            head = head->next; 

        }
        if(n == 1){
            lastElements[count%array_Size]->next = nullptr;
        }else if(n == count){
            start = start->next; 
        }
        else if(lastElements[count%array_Size] != lastElements[(count+2)%array_Size] ){
                    lastElements[count%array_Size]->next = lastElements[(count+2)%array_Size];

        }
       return start;

    }

    void printList(ListNode * head){

        while(head != nullptr){

            std::cout << head->val << " "; 
            head = head->next; 
        }
        std::cout << std::endl; 

    }
};

int main(){
    
    ListNode a(1),b(2),c(3),d(4),e(5), f(6); 
    a.next = &b; 
    b.next = &c;
    // c.next = &d; 
    // d.next = &e;
    //e.next = &f; 

    Solution s; 
    s.removeNthFromEnd(&a,3); 
    
    return 0; 

}
