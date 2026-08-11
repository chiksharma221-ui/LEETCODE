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
        ListNode* curr=head;
        ListNode* temp=head;
        ListNode *fut=NULL;
        ListNode* prev=NULL;
        int count=0;
        for(int i=0;i<k;i++)
        {
            if(temp==NULL)
                return head;
            temp=temp->next;
        }
        while(curr!=NULL && count<k)
        {
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
            count++;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};