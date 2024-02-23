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
    ListNode* partition(ListNode* head, int x) {
        ListNode*p1=new ListNode(-1);//part 1 head which  contain less than nodes
        ListNode*p2=new ListNode(-1);
        ListNode*tail1=p1;
        ListNode*tail2=p2;
        ListNode*curr=head;
        while(curr!=NULL)
        {
            if(curr->val<x)
            {
                tail1->next=curr;
                tail1=curr;
            }
            else
            {
                tail2->next=curr;
                tail2=curr;
            }
            curr=curr->next;
        }
        tail1->next=p2->next;
        tail2->next=NULL;
        return p1->next;
    }
};