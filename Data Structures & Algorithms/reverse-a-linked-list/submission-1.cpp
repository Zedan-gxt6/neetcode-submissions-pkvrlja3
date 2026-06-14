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
    void reverse(ListNode* par,ListNode* ch,ListNode** ans){
        if(!ch){
            *ans=par;
            return;
        } 
        reverse(ch,ch->next,ans);
        ch->next=par;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* ans;
        reverse(NULL,head,&ans);
        return ans;
    }
};
