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
    int getDecimalValue(ListNode* head) {
        int num=0;
        if(head==NULL) return num;
        ListNode*temp=head;

        while(temp!=NULL)
        {
            int val=temp->val;
            num=num*2+val;
            temp=temp->next;
        }
        return num;
    }
};