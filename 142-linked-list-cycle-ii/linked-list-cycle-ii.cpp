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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return head;
        }
        // ListNode* slow=head;
        // ListNode* fast=head;
        // while(fast && fast->next){
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     if(slow==fast){
        //         return slow;
        //     }
        // }
        // return slow;
        map<ListNode*,int> m;
        ListNode* curr=head;
        while(curr){
            m[curr]++;
            if(m[curr]==2){
                return curr;
            }
            curr=curr->next;
        }
        return NULL;
    }
};