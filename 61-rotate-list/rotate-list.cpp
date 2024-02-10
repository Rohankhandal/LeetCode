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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)
        {
            return head;
        }
        //first find length
        int len=1; //bcz we traverse at second last
        ListNode* tail=head;
        while(tail->next!=NULL)
        {
            len++;
            tail=tail->next;
        }
        cout<<"Lenght"<<len<<endl;
        if(k % len ==0) return head;  //IMP
        k=k%len;  //actual k
       
        // attach the tail node to head node
        tail->next=head;

        int goAtIndex=len-k;
        cout<<"Rem"<<goAtIndex<<endl;
        int cnt=1;  //DRY RUN
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(cnt==goAtIndex)
            {
                break;
            }
            temp=temp->next;
            cnt++;
        }
        head=temp->next;  //update the head;
        temp->next=NULL;

        return head;
    }
};