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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* curr=head;
        while(curr){
            count++;
            curr=curr->next;
        }
        if(count<k){
            return head;
        }
        count=0;
        curr=head;
        ListNode* pre=NULL;
        ListNode* n=NULL;
        while(curr && count<k){
            n=curr->next;
            curr->next=pre;
            pre=curr;
            curr=n;
            count++;
        }
        head->next=reverseKGroup(n,k);
        return pre;
    }
};