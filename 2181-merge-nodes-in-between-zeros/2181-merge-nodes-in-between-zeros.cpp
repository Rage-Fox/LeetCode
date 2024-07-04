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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* slow=head,*fast=head->next;
        while(slow!=NULL){
            int count=0;
            while(fast->val!=0){
                count+=fast->val;
                fast=fast->next;
            }
            slow->val=count;
            slow->next=fast->next;
            slow=slow->next;
            fast=fast->next;
        }
        return head;
    }
};