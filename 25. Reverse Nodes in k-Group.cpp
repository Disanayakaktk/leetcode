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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) { return head;}
        ListNode* current = head;
        vector<int> arr;
        while(current != nullptr) {
            arr.push_back(current->val);
            current = current->next;
        }
        int rounds = (arr.size()/k);
        int l = 0;
        int r = k-1;

        for(int i=0; i<rounds; i++) {
            int left = l;
            int right = r;
            while(left<right){
                int temp = arr[right];
                arr[right] = arr[left];
                arr[left] = temp;
                left++;
                right--;
            }
            l += k;
            r += k;
        }
        current = head;
        for(int i=0; i<arr.size(); i++) {
            current->val = arr[i];
            current = current->next;
        }
        return head;
    }
};
