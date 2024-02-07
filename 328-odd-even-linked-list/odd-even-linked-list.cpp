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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *oddHead=head;
        ListNode*odd=head;
        ListNode *evenHead=head->next;
        ListNode *evenTail=evenHead;
        while(evenTail!=NULL && evenTail->next!=NULL)
        {
            odd->next=odd->next->next;
            evenTail->next=evenTail->next->next;

            odd=odd->next;
            evenTail=evenTail->next;
        }
        odd->next=evenHead;
        return oddHead;
    }
};