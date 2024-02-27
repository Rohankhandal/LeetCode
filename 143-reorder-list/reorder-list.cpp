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
ListNode* findMiddle(ListNode*head)
{
    ListNode*fast=head->next;
    ListNode*slow=head;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}
ListNode* reverse(ListNode*head)
{
    if(head==NULL)
    {
        return head;
    }
    ListNode*prev=NULL;
    ListNode*curr=head;
    ListNode*forward=curr->next;
    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;

        prev=curr;
        curr=forward;
    }
    return prev;
}
    void reorderList(ListNode* head) {

        // Logic - reverse LL after middle node
        // then take 1-1 node from both halves

        ListNode*dummy=new ListNode(-1);
        ListNode*curr=dummy;

        ListNode*temp1=head;
        if(head==NULL || head->next==NULL)
        {
            return ;
        }
        ListNode*middleNode=findMiddle(head);        //O(N/2)
        // cout<<middleNode->val<<endl;
        ListNode*temp2=reverse(middleNode->next);    //O(N/2)
        // cout<<temp2->val<<endl;
        middleNode->next=NULL;
        int flag=1; //1 means take from start 
                    //0 means take from end
        while(temp2!=NULL || temp1!=NULL)         //O(N)
        { 
              // in odd case LL -> first has 1 node left (that's why use || operations)
            if(flag && temp1!=NULL)   //first add even
            {
                curr->next=temp1;
                curr=temp1;
                temp1=temp1->next;
            }
            else if(temp2!=NULL)    // add odd
            {
                curr->next=temp2;
                curr=temp2;
                temp2=temp2->next;
            }
            flag=!flag;
        }
        head=dummy->next;
    }
};