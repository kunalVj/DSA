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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next ==NULL || head==NULL){
            return NULL;
        }
         int countnodes =0;
        ListNode* temp=head;
        while(temp != NULL){
            temp=temp->next;
            countnodes++;
            
        }
        int n=(countnodes/2)-1;
        temp=head;
        while(n--){
            temp= temp->next;
        }
        
        temp->next=temp->next->next;
        return head;
        
        
        
    }
};