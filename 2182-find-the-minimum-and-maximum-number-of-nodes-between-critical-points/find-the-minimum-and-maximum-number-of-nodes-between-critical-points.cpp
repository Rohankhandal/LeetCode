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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans(2,-1);
        int minDis=INT_MAX;
        int maxDis=INT_MIN;
        ListNode*prev=head;
        ListNode*curr=head->next;
        int count=2;
        vector<int>dis;
        while(curr->next!=NULL)
        {
            if(curr->val>prev->val && curr->val>curr->next->val)
            {
               dis.push_back(count);
            }
            if(curr->val<prev->val && curr->val<curr->next->val)
            {
                dis.push_back(count);
            }
            count++;
            prev=curr;
            curr=curr->next;
        }
        if(dis.size()>=2)
        {
            cout<<"HELLO";
             maxDis=abs(dis[dis.size()-1]-dis[0]);
            for(int i=1;i<dis.size();i++)
            {
                minDis=min(minDis,abs(dis[i]-dis[i-1]));
            }
            ans[0]=minDis;
            ans[1]=maxDis;
        }
       
        
        return ans;

    }
};