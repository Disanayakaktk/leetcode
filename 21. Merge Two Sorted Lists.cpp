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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* MergedList = new ListNode();
        ListNode * head3 = MergedList;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                head3->next = list1;
                head3 = list1;
                list1 = list1->next; 
            }
            else if(list1->val > list2->val){
                head3->next = list2;
                head3 = list2;
                list2 = list2->next;
            }
        }
        if(list1 == nullptr){
            while(list2 != nullptr){
                head3->next = list2;
                head3 = list2;
                list2 = list2->next;
            }
        }
        else if(list2 == nullptr){
            while(list1 != nullptr){
                head3->next = list1;
                head3 = list1;
                list1 = list1->next; 
            }
        }
    return MergedList->next;

    }
};
