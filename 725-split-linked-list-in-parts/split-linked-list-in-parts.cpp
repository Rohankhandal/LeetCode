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
    int len=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        if(head==NULL)
        {
            while(k--)
            {
                ans.push_back({});
            }
            return ans;
        }
        int len=getLength(head);
        int divPart=len/k;
        int rem=len%k;
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(k--)
        {
            prev=NULL;
            ans.push_back(temp);
            int count=0;
            while(count<divPart && temp)
            {
                prev=temp;
                temp=temp->next;
                count++;
                // cout<<"WHILE"<<endl;
                
            }
            
            if(rem && temp)  //insert one by one rem part in split part if exist
            {
                prev=temp;
                temp=temp->next;
                rem--;
                // cout<<"IF"<<endl;
            }
            // if(temp)cout<<"J"<<temp->val<<endl;
            // if(prev)cout<<"P:"<<prev->val<<endl;
            if(prev) prev->next=NULL;
        }

        return ans;
    }
};