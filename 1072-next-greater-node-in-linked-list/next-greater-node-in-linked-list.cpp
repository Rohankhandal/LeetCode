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
    ListNode *reverseLL(ListNode*head)
    {
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *forward=head->next;
        while(curr!=NULL)
        {
            forward=curr->next;

            curr->next=prev;

            prev=curr;
            curr=forward;
        }
        return prev;

    }
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int>st;
        vector<int>ans;
        head=reverseLL(head);
        ListNode*temp=head->next;
        ans.push_back(0);
        st.push(head->val);
        while(temp!=NULL)
        {
            while(!st.empty() && temp->val>=st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(st.top());
            }
            st.push(temp->val);
            temp=temp->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};