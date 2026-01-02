 // Definition for singly-linked list.
//  struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // find length of this linked list
        int length = 0;
        ListNode* current = head;

        while( current != nullptr ) {
            length++;
            current = current->next;
        }
        // removing the head node if length = n
        if(length == n) {
            ListNode* newHead = head->next;
            delete head;  // reduce memory waste
            return newHead;
        }

        // move to the previous node of the node which should remove
        length = length-n;
        current = head;
        for( int i=1;i<length;i++ ) {
            current = current->next;
        }
        // skip the node which should remove
        ListNode* temp = current->next;
        current->next = temp->next;
        delete temp;   // reduce memory waste

        return head;
    }
};
