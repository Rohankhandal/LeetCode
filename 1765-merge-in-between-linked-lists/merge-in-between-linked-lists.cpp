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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(list1==NULL) return list2;
        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=list1;
        ListNode*temp=dummyNode;

        while(a>0)
        {
            temp=temp->next;
            a--;
        }
        ListNode*forward=list1;
        while(b>0)
        {
            forward=forward->next;
            b--;
        }
        // cout<<temp->val<<" "<<forward->val<<endl;
        ListNode*tail2=list2;
        while(tail2->next!=NULL)
        {
            tail2=tail2->next;
        }
        
        temp->next=list2;
        tail2->next=forward->next;
        return list1;
    }
};