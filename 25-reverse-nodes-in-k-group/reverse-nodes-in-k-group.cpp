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
    int getLength(ListNode* &head)
    {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* &head, int &k) {
        if(head==NULL){
            return head;
        }
        //invalid case
        int len=getLength(head);
        if(k>len)   //this is important for when last there is no nodes of length k
        {
            return head;
        }
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *forward=curr->next;
        int count=0;
        while(count<k)
        {
            forward=curr->next;
            curr->next=prev;

            prev=curr;
            curr=forward;
            count++;
        }
        if(curr!=NULL)
        {
            head->next=reverseKGroup(curr,k);
        }
        return prev;
    }
};