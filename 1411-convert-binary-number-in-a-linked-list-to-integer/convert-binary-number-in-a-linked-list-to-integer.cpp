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
ListNode* reverse(ListNode*head)
{
    if(head==NULL || head->next==NULL) return head;
    ListNode*curr=head;
    ListNode*prev=NULL;
    ListNode*forward=head;
    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;

        prev=curr;
        curr=forward;
    }
    return prev;
}
    int getDecimalValue(ListNode* head) {
        //reverse the LL
        head=reverse(head);
        int ans=0;
        int i=0;
        while(head!=NULL)
        {
            ans+=pow(2,i)*head->val;
            head=head->next;
            i++;
        }
        return ans;
    }
};