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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        //make markers for current Node and for the node before reverseing
        ListNode*leftPre=dummy;
        ListNode*currNode=head;
        for(int i=0;i<left-1;i++)
        {
            leftPre=leftPre->next;
            currNode=currNode->next;
        }

        //make a marker to node where we start reversing
        ListNode*subListHead=currNode;

        ListNode*preNode=NULL;
        for(int i=0;i<=right-left;i++)
        {
            ListNode* nextNode=currNode->next;
            currNode->next=preNode;
            preNode=currNode;
            currNode=nextNode;
        }

        //join the pieces;
        leftPre->next=preNode;
        subListHead->next=currNode;

        return dummy->next;
    }
};













//  FIrst METHOD:


// class Solution {
// public:
// ListNode* reverse(ListNode* head)
// {
//     ListNode*prev=NULL;
//     ListNode*curr=head;
//     // cout<<"CURR"<<curr<<endl;
//     ListNode*forward=curr->next;
//     while(curr!=NULL)
//     {
//         forward=curr->next;
//         curr->next=prev;

//         prev=curr;
//         curr=forward;
//     }
//     return prev;
// }
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         // if(head==NULL || (head->next==NULL && left==1 && right==1))
//         // return head;
//         ListNode*dummy=new ListNode(-1);
//         dummy->next=head;

//         ListNode*prev=dummy;
//         ListNode*curr=dummy->next;
//         ListNode*forward=curr->next;

//         int count=1;
//         while(curr!=NULL)
//         {
//             forward=curr->next;
//             if(count==left)
//             {
//                 break;
//             }
//             prev=curr;
//             curr=forward;
//             count++;
//         }
//         //now point right index node to null
        
//         while(curr!=NULL)
//         {
//             forward=curr->next;
//             if(count==right)
//             {
//                 break;
//             }
            
//             curr=forward;
//             count++;
//         }
       
//         if(curr)  //if right index is not at last node then update right index next value to NULL
//         //for reverse the range nodes
//           curr->next=NULL;

//          ListNode* subListHead=prev->next;  //last node after reverse the LL

//         //now reverse left index to right index  nodes
//         prev->next=reverse(prev->next);
      
        

//        //point after right index values to reversed LL tail
//         subListHead->next=forward;


//         return dummy->next;
//     }
// };