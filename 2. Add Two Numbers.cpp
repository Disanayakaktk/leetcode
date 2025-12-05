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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Initialize a new linkedList
        ListNode* result = new ListNode();
        ListNode* current = result;   // define a tempary traversal point
        int carry = 0;     
                   // Check whether l1 & l2 are pointed as null points
                   // if l1 & l2 are pointed check the carry to continue
        while(l1 != nullptr || l2 != nullptr || carry!=0){
            int sum = carry;
            if(l1 != nullptr){
                sum += l1->val; // add l1 value of the current position 
                l1 = l1->next; // traverse to the next node
            }
            if(l2 != nullptr){
                sum += l2->val; // add l2 value of the current position 
                l2 = l2->next; // traverse to the next node
            }
            carry = sum/10;     // get the carry from total sum(l1_val+l2_val+previous_carry)
            current->next = new ListNode(sum%10); // create a new node by including LSD(sum%10)
            current = current->next;   // Move to the new node
        }
        return result->next;     
    }
};
