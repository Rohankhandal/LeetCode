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
    ListNode* findMid(ListNode *head)
    {
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    //MERGED TWO SORTED LIST
     ListNode* merge(ListNode* left, ListNode* right) {
       if(left==0)  return right;
       if(right == 0) return left;

       ListNode* ans=new ListNode(-1);
       ListNode *mptr=ans;   // merged pointer

       while(left && right)
       {
           if(left->val <= right->val)
           {
               mptr->next=left;
               mptr=left;
               left=left->next;
           }
           else    //(left->val > right->val)
           {
               mptr->next=right;
               mptr=right;
               right=right->next;
           }
       }

       if(left)
       {
           mptr->next = left;  //if left LL is exist, then connect entire remain LL to last node of mptr.
        //    mptr=left;
        //    left=left->next;
       }
       
       if(right)  //if right LL is exist, then connect entire remain LL to last node of mptr.
       {
           mptr->next = right;
        //    mptr=left;
        //    left=left->next;
       }

       return ans->next;   //bcz first node contain -1 so we return ans->next
    }



    ListNode* sortList(ListNode* head) {
        if(head==0 || head->next==0)
        {
            return head;
        }

        //Break LL into two halves using mid node.
        ListNode *mid=findMid(head);
        ListNode *left=head;     //created two sublinked list
        ListNode *right=mid->next;
        mid->next=0;

        //sort RE
        left=sortList(left);
        right=sortList(right);


        //merge both left ans right LLs
        ListNode *mergedLL=merge(left,right);
        return mergedLL;
    }
};

// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         vector<int> vec;
//         ListNode *temp = head;

//         while(temp != NULL){
//             vec.push_back(temp->val);
//             temp = temp->next;
//         }
//         sort(vec.begin(),vec.end());

//         temp = head;
//         int i = 0;
//         while(temp != NULL){
//             temp->val = vec[i++];
//             temp = temp->next;
//         }
//         return head;
//     }
// };