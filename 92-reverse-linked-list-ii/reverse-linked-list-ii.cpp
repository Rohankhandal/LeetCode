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
ListNode* reverse(ListNode* head)
{
    ListNode*prev=NULL;
    ListNode*curr=head;
    // cout<<"CURR"<<curr<<endl;
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || (head->next==NULL && left==1 && right==1))
        return head;
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*prev1=dummy;
        ListNode*curr=dummy->next;
        ListNode*forward=curr->next;
        int count=1;
        while(curr!=NULL)
        {
            forward=curr->next;
            if(count==left)
            {
                break;
            }
            prev1=curr;
            curr=forward;
            count++;
        }
        //now point right val node to null
        
        while(curr!=NULL)
        {
            forward=curr->next;
            if(count==right)
            {
                break;
            }
            
            curr=forward;
            count++;
        }
        if(curr)
        curr->next=NULL;

        //now reverse left node to right node
        prev1->next=reverse(prev1->next);
        // cout<<"prev"<<prev1->val<<endl;
        //traverse to end node;
        while(prev1->next!=NULL)
        {
            // cout<<"Prev:"<<prev1->val<<endl;
            prev1=prev1->next;
            
        }
        // cout<<"prev_>NEXT"<<prev1->val<<" "<<prev1->next<<endl;
        // cout<<"Forward"<<forward<<endl;
        prev1->next=forward;


        return dummy->next;
    }
};