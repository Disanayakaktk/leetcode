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
    ListNode* swapPairs(ListNode* head) {
        ListNode* current= head;
        while( current != nullptr && current->next != nullptr ) {
            ListNode* first = current;
            ListNode* second = current->next;
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
            current = second->next; 
        }
        return head;
    }
};
