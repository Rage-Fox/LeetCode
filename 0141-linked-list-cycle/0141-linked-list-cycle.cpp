/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
// Floyd’s Cycle-Finding Algorithm // fast slow approach // 2 pointers // "tortoise and the hare algorithm"
    bool hasCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};