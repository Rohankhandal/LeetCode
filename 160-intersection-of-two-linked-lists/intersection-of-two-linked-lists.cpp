/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// T.C: O(2*max(length of list1,length of list2))
class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
        {
            return NULL;
        }
        ListNode*temp1=headA;
        ListNode*temp2=headB;
        while(temp1!=temp2)  //this condition is true when both points to NULL
        //else inside condition take care of other conditions
        {
            temp1=temp1->next;
            temp2=temp2->next;

            if(temp1==temp2) return temp1;

            //Main logic if node is nUll then start the traverse from
            //opposite node
            if(temp1==NULL) temp1=headB;
            if(temp2==NULL) temp2=headA;
        }
        return temp1;
    }
};



 //T.C:-O(N1+2N2)
// class Solution {
// public:
// int getLength(ListNode* head)
// {
//     int len=0;
//     while(head!=NULL)
//     {
//         len++;
//         head=head->next;
//     }
//     return len;
// }
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int len1=getLength(headA);
//         int len2=getLength(headB);
//         if(len1>len2)
//         {
//             int rem=len1-len2;
           
//             while(rem--)
//             {
//                 headA=headA->next;
//             }
//         }
//         else
//         {
//             int rem=len2-len1;
            
//             while(rem--)
//             {
//                 headB=headB->next;
//             }
//         }
//         ListNode*l1=headA;
//         ListNode*l2=headB;
//         while(l1!=NULL && l2!=NULL)
//         {
//             if(l1==l2)
//             {
//                 return l1;
//             }
//             l1=l1->next;
//             l2=l2->next;
//         }
//         return NULL;
//     }
// };