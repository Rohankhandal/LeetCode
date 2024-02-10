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
ListNode* merge(ListNode* l1,ListNode* l2)
{
    if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
    ListNode* dummyNode=new ListNode(-1);
    ListNode* ansPtr=dummyNode;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val < l2->val)
        {
            ansPtr->next=l1;
            ansPtr=l1;
            l1=l1->next;
            
        }
        else {
            ansPtr->next=l2;
            ansPtr=l2;
            l2=l2->next;
            
        }
    }
    if(l1)
    {
        ansPtr->next=l1;
    }
    if(l2)
    {
        ansPtr->next=l2;
    }
    return dummyNode->next;

}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
        {
            return NULL;
        }
        if(n==1)
        {
            return lists[0];
        }
        ListNode *head=lists[0];
        for(int i=1;i<lists.size();i++)
        {
            head=merge(head,lists[i]);
        }
        return head;
    }
};