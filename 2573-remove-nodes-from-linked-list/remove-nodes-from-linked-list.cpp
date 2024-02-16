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
ListNode* reverse(ListNode* head)
{
    ListNode*curr=head;
    ListNode*prev=NULL;
    ListNode*forward=curr->next;
    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;

        prev=curr;
        curr=forward;


    }
    return prev;
}
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        head=reverse(head);
        ListNode*curr=head;
        

        int maxi=curr->val;
        ListNode*prev=NULL;
        while(curr!=NULL)
        {
            if(curr->val<maxi)
            {
                //remving the node
                ListNode* del=curr;

                prev->next=curr->next;
                curr=curr->next;

                del->next=NULL;
                delete del;
                
            }
            else{
                //update maximum value
                maxi=curr->val;
                prev=curr;
                curr=curr->next;
            }
        }
        head=reverse(head);
        return head;


    }
};



//  T.c:-O(N)
//  S.c:-O(N)
// class Solution {
// public:
// void storeNodes(stack<ListNode*>&st,ListNode* head)
// {
//     ListNode* temp=head;
//     while(temp!=NULL)
//     {
//         st.push(temp);
//         temp=temp->next;

//     }

// }
//     ListNode* removeNodes(ListNode* head) {
//         stack<ListNode*>st;
//         storeNodes(st,head);
//         ListNode*prev=st.top();
//         st.pop();
//         int maxi=prev->val;
//         while(!st.empty())
//         {
//             ListNode*front=st.top();
//             st.pop();
//             if(front->val<maxi)
//             {
//                 if(!st.empty()) 
//                 {
//                     ListNode*temp=st.top();
//                     temp->next=prev;
//                     delete front;
//                 }
//             }
//             else{
//                 prev=front;
//                 maxi=front->val;
//             }
//         }

//         return prev;
        
//     }
// };