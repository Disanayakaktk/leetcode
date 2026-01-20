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



// THis code is time efficent (0ms Beats 100.00%)

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        vector<int> temp;
        ListNode* head;
        ListNode* tail;

        for(int i=0; i<k; i++) {
            head = lists[i];
            while(head != nullptr) {
                temp.push_back(head->val);
                head = head->next;
            }
        }
        sort(temp.begin(), temp.end());
        int n = temp.size();
        for(int i=0; i<n; i++) {
            ListNode* node = new ListNode(temp[i]);
            if(!head) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
        return head;
    }
};


// This is useful for memory waste. It free some memory space by deleting linked lists inside the input array list 
// But runtime is high compare to above (7ms Beats 33.72%)

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        vector<int> temp;
        ListNode* head;
        ListNode* tail;

        for(int i=0; i<k; i++) {
            head = lists[i];
            while(head != nullptr) {
                temp.push_back(head->val);
                tail = head->next;
                delete head;
                head = tail;
            }
        }
        sort(temp.begin(), temp.end());
        int n = temp.size();
        for(int i=0; i<n; i++) {
            ListNode* node = new ListNode(temp[i]);
            if(!head) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
        return head;
    }
};
