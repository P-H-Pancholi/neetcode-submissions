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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        
        while(true){
            int min_index = -1, min_val = INT_MAX;
            for(int i = 0; i < lists.size(); i++){
                if(lists[i] != nullptr){
                    if(lists[i]->val < min_val){
                        min_val = lists[i]->val;
                        min_index = i;
                    }
                }
            }
            if(min_index == -1){
                break;
            }
            ListNode* currNode = new ListNode(min_val);
            curr->next = currNode;
            curr = currNode;
            lists[min_index] = lists[min_index]->next;
        }
        return head->next;
    }
};
