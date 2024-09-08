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
    int getLength(ListNode*head)
    {
        ListNode*temp=head;
        int len=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=getLength(head);
        cout<<len<<endl;
        int size=len/k;
        int rem=len%k;
        ListNode*temp=head;
        vector<ListNode*>ans;
        while(temp!=NULL)
        {
            ans.push_back(temp);
            ListNode* del=temp;
            int cnt=1;
            while(cnt<size+(rem>0))
            {
                temp=temp->next;
                cnt++;
            }
            rem--;
             
            del=temp;
            if(temp!=NULL)
                temp=temp->next;
            if(del!=NULL)
            del->next=NULL;
            k--;
        }
        while(k--)
        {
            ans.push_back(NULL);
        }
        return ans;
    }
};