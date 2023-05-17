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
    int pairSum(ListNode* head) {
// find the middle of the linked list 
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        // reverse the second half of the linked list

        ListNode* prev = NULL;
        ListNode* nextnode = NULL;

        while(slow != NULL){
            nextnode = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = nextnode;
        }
        int maxSum = 0;
        ListNode* start = head;
// To obtain twin sums, we use the corresponding nodes of the given linked list and the reversed linked list.
        while(prev != NULL){
            maxSum = max(maxSum, start -> val + prev -> val);
            prev = prev -> next;
            start = start -> next;
        }

        return maxSum;
    }
    // TC =O(N);
    // SC = O(1);
};
/*
ListNode* curr = head;
        vector<int> ListVal;

        while(curr != NULL){
            ListVal.push_back(curr->val);
            curr = curr -> next;
        }

        int i = 0;
        int j = ListVal.size() - 1;
        int maxSum = 0;

        while(i < j){
            maxSum = max(maxSum, ListVal[i] + ListVal[j]);
            i++;
            j--;
        }

        return maxSum;
        // TC = O(N)
        // SC = O(N)
*/