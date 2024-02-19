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
int getLength(ListNode* head)
{
    ListNode*temp=head;
    int len=0;
    while(temp)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        int startIndex=k;
        int len=getLength(head);
        int endIndex=len-k+1;  //IMP PART

        ListNode*temp=head;
        int i=0;
        ListNode*first=NULL;
        ListNode*second=NULL;
        
            while(i<startIndex-1)
            {
                temp=temp->next;
                i++;
            }
            first=temp;
cout<<"FIrst"<<first->val<<endl;
            temp=head;
            i=0;
            while(i<endIndex-1)
            {
                temp=temp->next;
                i++;
            }
            second=temp;
            cout<<"Second"<<second->val<<endl;
            swap(first->val,second->val);
            
        return head;
    }
};