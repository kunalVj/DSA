/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL){
            return NULL;
        }
        // two pointers

        ListNode* curr = head;
        ListNode* prev = NULL;
        while(left > 1){ // moving the two pointers until they reach the correct position 
            prev = curr;
            curr = curr -> next;
            left--;
            right--;
        }
        // curr will be on reverse starting point 

        ListNode* BeforeLeft = prev; // store the prev we need it later to connect it to reversed part
        ListNode* tail = curr; // store starting of reverse list so we can link it to tail after reversing
        ListNode* forward = NULL;

        // reverse until we reach the last of the given range 
        while(right > 0){ 
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            right--;
        }
        // make the final LL
        if(BeforeLeft != NULL){
            BeforeLeft -> next = prev;
            }
        else{
            head = prev; 
        }

        tail -> next = curr;

        return head;
    }
};