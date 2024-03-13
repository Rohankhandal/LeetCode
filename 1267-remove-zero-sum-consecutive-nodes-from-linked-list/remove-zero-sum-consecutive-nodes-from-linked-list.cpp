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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>mp;  //prefixSum->Nodes
        int preSum=0;
        ListNode*dummyNode=new ListNode(-1);
        dummyNode->next=head;

        mp[0]=dummyNode;
        while(head!=NULL)
        {
            preSum+=head->val;
            if(mp.find(preSum)!=mp.end())
            {
                //actual code
                ListNode*start=mp[preSum];  //node which have same preSum in map
                //traverse from start node and delete all entries in map
                ListNode*temp=start->next;
                int pSum=preSum;
                while(temp!=head)
                {
                    pSum+=temp->val;
                    mp.erase(pSum);

                    temp=temp->next;
                }
                start->next=head->next;
            }
            else
            {
                mp[preSum]=head;
            }
            head=head->next;
        }
        return dummyNode->next;
    }
};