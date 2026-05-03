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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nthNodeprev = nullptr;
        ListNode* curr = head;
        int i = 0;
        while(curr){
            if(nthNodeprev == nullptr)
            {
                if(i == n){
                    nthNodeprev = head;
                }   
            }else{
                nthNodeprev = nthNodeprev->next;
            }
            curr = curr->next;
            i++;
        }
        if(!nthNodeprev){
            return head->next;
        }
        ListNode* nthNode = nthNodeprev->next;
        nthNodeprev->next = nthNode == nullptr ? nullptr : nthNode->next;
        return head;
    }
};
