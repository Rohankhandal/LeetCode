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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
     {
                    stack<int> s1,s2;
					while(l1)
					{
						s1.push(l1->val);
						l1=l1->next;
					}
					while(l2)
					{
						s2.push(l2->val);
						l2=l2->next;
					}
					ListNode* dummy=new ListNode(0);
					int sum=0;
					while(!s1.empty() || !s2.empty())
					{
						if(!s1.empty())
						{
							sum+=s1.top();
							s1.pop();
						}
						if(!s2.empty())
						{
							sum+=s2.top();;
							s2.pop();
						}
						dummy->val=sum%10;  //insert data in node if data exist
						ListNode* head=new ListNode(sum/10);  //insert carry in new node (for future , if next iteration is execute)
						head->next=dummy;  //insert at start , so that no need to store in stack or reverse it
						dummy=head;
						sum/=10;  //carry 
					}
					return dummy->val==0? dummy->next:dummy; 
                       //IMP POINT 
                       //if at last time if carry is zero , then ans is dummy->val
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
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         if(!l1)
//             return l2;
//         if(!l2)
//             return l1;
//         stack<int>s1;
//         stack<int>s2;
//         stack<int>ans;
//         ListNode*temp1=l1;
//         ListNode*temp2=l2;

//         while(temp1)
//         {
//             s1.push(temp1->val);
//             temp1=temp1->next;
//         }
        
//         while(temp2)
//         {
//             s2.push(temp2->val);
//             temp2=temp2->next;
//         }
//         int carry=0;
//         int sum=0,digit;
//         while(!s1.empty() && !s2.empty())
//         {
//             int num1=s1.top();
//             s1.pop();
//             int num2=s2.top();
//             s2.pop();
//             sum=carry+num1+num2;
//             digit=sum%10;
//             carry=sum/10;
//             // cout<<"DIGIT:"<<digit<<endl;
//             ans.push(digit);
//         }
//         while(!s1.empty())
//         {
            
//             int num1=s1.top();
//             s1.pop();
//             sum=carry+num1;
//             digit=sum%10;
//             carry=sum/10;
//             // cout<<"DIGIT:"<<digit<<endl;
//             ans.push(digit);
//         }
//         while(!s2.empty())
//         {
//             int num2=s2.top();
//             s2.pop();
//             sum=carry+num2;
//             digit=sum%10;
//             carry=sum/10;
//             // cout<<"DIGIT:"<<digit<<endl;
//             ans.push(digit);
//         }
//         while(carry)
//         {
           
//             sum=carry;
//             digit=sum%10;
//             carry=sum/10;
//             ans.push(digit);
//         }


//         //now convert stack ans into linked list
//         ListNode*newAns=new ListNode(-1);
//         ListNode* list=newAns;
//         while(!ans.empty())
//         {
//             ListNode*temp = new ListNode(ans.top());
//             ans.pop();
//             list->next=temp;
//             temp->next=NULL;
//             list=temp;
            
//         }

//         return newAns->next;
        
//     }
// };