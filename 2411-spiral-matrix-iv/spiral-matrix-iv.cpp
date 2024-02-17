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
        vector<vector<int>>ans(m,vector<int>(n,-1)); //intial value of matrix is -1
        ListNode* temp=head;
        int rowStart=0;
        int rowEnd=m-1;
        int colStart=0;
        int colEnd=n-1;
        
        while(temp)
        {
            for(int i=colStart;i<=colEnd&&temp;i++)
            {
                ans[rowStart][i]=temp->val;
                temp=temp->next;
            }
            rowStart++;
            for(int i=rowStart;i<=rowEnd&&temp;i++)
            {
                ans[i][colEnd]=temp->val;
                temp=temp->next;
            }
            colEnd--;
            for(int i=colEnd;i>=colStart&&temp;i--)
            {
                ans[rowEnd][i]=temp->val;
                temp=temp->next;
            }
            rowEnd--;
            for(int i=rowEnd;i>=rowStart&&temp;i--)
            {
                ans[i][colStart]=temp->val;
                temp=temp->next;
            }
            colStart++;
        }
        return ans;
    }
};