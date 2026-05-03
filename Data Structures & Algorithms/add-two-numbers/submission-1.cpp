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
        bool carry = false;
        ListNode* prev = nullptr;
        ListNode* head = nullptr;
        while(l1 && l2){
            int res = l1->val + l2->val;
            if(carry){
                res++;
                carry = false;
            }
            if(res > 9){
                res = res%10;
                carry = true;
            }
            ListNode* curr = new ListNode(res);
            if(prev != nullptr){
                prev->next = curr;
            }else{
                head = curr;
            }
            prev = curr;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int res = l1->val;
            if(carry){
                res++;
                carry = false;
            }
            if(res > 9){
                res = res%10;
                carry = true;
            }
            ListNode* curr = new ListNode(res);
            if(prev != nullptr){
                prev->next = curr;
            }else{
                head = curr;
            }
            prev = curr;
            l1 = l1->next;
        }
        while(l2){
            int res = l2->val;
            if(carry){
                res++;
                carry = false;
            }
            if(res > 9){
                res = res%10;
                carry = true;
            }
            ListNode* curr = new ListNode(res);
            if(prev != nullptr){
                prev->next = curr;
            }else{
                head = curr;
            }
            prev = curr;
            l2 = l2->next;
        }
        if(carry){
            ListNode* curr = new ListNode(1);
            prev->next = curr;
        }
        return head;
    }
};
