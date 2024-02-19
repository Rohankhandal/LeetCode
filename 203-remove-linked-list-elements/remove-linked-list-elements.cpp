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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
          return head;
        while(head!=NULL&&head->val==val)
        {
            ListNode*del=head;
            head=head->next;
            del->next=NULL;
            delete del;
        }
        if(head==NULL)
          return head;
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp!=NULL)
        {
            if(temp->val==val )
            {
                ListNode*del=temp;
                
                prev->next=temp->next;
                
                temp=temp->next;
                del->next=NULL;
                delete del;
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
            
        }
        return head;
    }
};