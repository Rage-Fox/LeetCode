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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> array(2,0);
        if(!head or !head->next or !head->next->next){
            return {-1,-1};
        }
        ListNode* first=head,*second=head->next,*third=head->next->next;
        int index=2,greater=-1,min=INT_MAX,minDistance=INT_MAX;
        while(third){
            if((second->val>first->val and second->val>third->val) or (second->val<first->val and second->val<third->val)){
                if(greater!=-1){
                    int diff=index-greater;
                    if(minDistance>diff){
                        minDistance=diff;
                    }
                }
                greater=index;
                if(min>greater){
                    min=greater;
                }
            }
            index++;
            first=first->next;
            second=second->next;
            third=third->next;
        }
        array[0]=minDistance==INT_MAX?-1:minDistance;
        array[1]=(min==INT_MAX or min==greater)?-1:greater-min;
        return array;
    }
};