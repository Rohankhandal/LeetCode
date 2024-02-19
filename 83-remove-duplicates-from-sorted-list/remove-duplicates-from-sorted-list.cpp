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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
      ListNode*prev=head;
      ListNode*temp=prev->next;

      while(temp!=NULL)
      {
          if(temp->val==prev->val)
          {
              temp=temp->next;
              continue;
          }
          prev->next=temp;
          prev=temp;
          temp=temp->next;
      }

      prev->next=NULL;  //IMP at last if temp goes to NULL , then loop is end
      //without updating the prev
      //e.g 1->2->2->3->4->4->4->NULL
      return head;
    }
};








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
//     ListNode* deleteDuplicates(ListNode* head) {
//       if(head==NULL || head->next==NULL)
//       {
//           return head;
//       }   
//       ListNode*temp=head;
//       while(temp!=NULL && temp->next!=NULL)
//       {
//           while(temp!=NULL && temp->next!=NULL && temp->val==temp->next->val)
//           {
//               ListNode*del=temp->next;
//               temp->next=temp->next->next;
//               //update temp
//               //   temp=temp->next;  //we can't update until all matching number are not delete (if all matching numbers are in sequence)
//               //delete the node
//               delete del;
//           }
          
//               temp=temp->next;
          
//       }
//       return head;
//     }
// };