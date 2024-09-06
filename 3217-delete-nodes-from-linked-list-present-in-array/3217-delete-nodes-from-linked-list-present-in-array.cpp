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
    ListNode* modifiedList(vector<int> &hnums,ListNode* hhead){
        unordered_set<int> hSet(hnums.begin(),hnums.end());
        ListNode hdummy(0);
        hdummy.next=hhead;
        ListNode* hprev=&hdummy,*hcurr=hhead;
        while(hcurr!=NULL){
            if(hSet.find(hcurr->val)!=hSet.end()){
                hprev->next=hcurr->next;
            }
            else{
                hprev=hcurr;
            }
            hcurr=hprev->next;
        }
        return hdummy.next;
    }
};