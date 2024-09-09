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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));

        int total=m*n;
        int rStart=0;
        int rEnd=m-1;
        int cStart=0;
        int cEnd=n-1;
        while(head!=NULL)
        {
            for(int i=cStart;i<=cEnd && head!=NULL;i++)
            {
                ans[rStart][i]=head->val;
                head=head->next;
               
            }
            rStart++;

            for(int i=rStart;i<=rEnd && head!=NULL;i++)
            {
                ans[i][cEnd]=head->val;
                head=head->next;
            }
            cEnd--;

            for(int i=cEnd;i>=cStart && head!=NULL;i--)
            {
                ans[rEnd][i]=head->val;
                head=head->next;
            }
            rEnd--;

            for(int i=rEnd;i>=rStart && head!=NULL;i--)
            {
                ans[i][cStart]=head->val;
                head=head->next;
            }
            cStart++;
            
        }   
        return ans;
    }
};