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
    ListNode* removeElements(ListNode* head, int val) {
        //create a dummmy node , and add head to dummy node so that ,
        //we can delete nodes from starting also
        if(head==NULL)
         return head;
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;

        ListNode*curr=dummy;
        while(curr->next!=NULL)
        {
            //check if value matches
            if(curr->next->val==val)
            {
                curr->next=curr->next->next;
            }
            else
            {
                curr=curr->next;
            }
        } 

        return dummy->next;
        //return the head node;
    }
};






// Good but have messy code
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         if(head==NULL)
//           return head;
//         while(head!=NULL&&head->val==val)  //removing the nodes in starting 
//         {
//             ListNode*del=head;
//             head=head->next;
//             del->next=NULL;
//             delete del;
//         }
//         if(head==NULL)
//           return head;
//         ListNode*temp=head;
//         ListNode*prev=NULL;

//         while(temp!=NULL)  //deleting  nodes 
//         {
//             if(temp->val==val )
//             {
//                 ListNode*del=temp;
                
//                 prev->next=temp->next;
                
//                 temp=temp->next;
//                 del->next=NULL;
//                 delete del;
//             }
//             else
//             {
//                 prev=temp;
//                 temp=temp->next;
//             }
            
//         }
//         return head;
//     }
// };