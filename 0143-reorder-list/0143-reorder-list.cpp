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
    void reorderList(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *h2=slow->next;
        slow->next=NULL;
        ListNode *tail=NULL;
        // Reverse the second half of the linked list
        while(h2){
            ListNode *temp=h2->next;
            h2->next=tail;
            tail=h2;
            h2=temp;
        }
        ListNode *h1=head;
        h2=tail;
        while(h2){
            ListNode *temp1=h1->next;
            ListNode *temp2=h2->next;
            h1->next=h2;
            h2->next=temp1;
            h1=temp1;
            h2=temp2;
        }        
    }
};