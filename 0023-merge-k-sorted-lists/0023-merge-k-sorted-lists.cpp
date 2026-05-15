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
    // Sort and merge two linked lists
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* merged=new ListNode(0);
        ListNode* temp=merged;
        while(left && right){
            if(left->val<right->val){
                temp->next=left;
                left=left->next;
            }
            else{
                temp->next=right;
                right=right->next;
            }
            temp=temp->next;
        }
        while(left){
            temp->next=left;
            left=left->next; 
            temp=temp->next;
        }
        while(right){
            temp->next=right;
            right=right->next;
            temp=temp->next;
        }
        return merged->next;
    }
    // Merge sort recursively
    ListNode* mergeSort(vector<ListNode*> &lists,int st,int end){
        if(st>=end){
            return lists[st];
        }
        int mid=st+(end-st)/2;
        ListNode* left=mergeSort(lists,st,mid);
        ListNode* right=mergeSort(lists,mid+1,end);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        return mergeSort(lists,0,lists.size()-1);
    }
};