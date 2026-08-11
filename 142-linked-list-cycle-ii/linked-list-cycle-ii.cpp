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
        ListNode* temp=head;
        unordered_map<ListNode*,int>m;
        int i=0;
        while(temp!=NULL)
        {
            if(m.count(temp))
            {
                cout<<"tails connects to node index"<<m[temp]<<endl;
                return temp;
            }
            m[temp]=i;
            i++;
            temp=temp->next;
        }
        cout<<"no cycle";
        return NULL;
    }
};