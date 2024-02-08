/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode* fast=head;
       ListNode* slow=head;
       while(fast!=NULL)
       {
           fast=fast->next;
           if(fast!=NULL)
           {
               fast=fast->next;
               slow=slow->next;
           }
           if(fast==slow)
           {
               return true;
           }
       }
       return false;
    }
};



//  . The insertion and search operations in the unordered_map have a worst-case time 
//  complexity of O(log(N)). As the loop iterates through N nodes, the total time 
//  complexity is determined by the product of the traversal (O(N)) and the 
//  average-case complexity of the hashmap operations (insert and search), 
//  resulting in O(N * 2 * log(N)). 
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_map<ListNode*,int>mp;
//         ListNode*temp=head;
//         while(temp!=NULL)
//         {
//             if(mp.find(temp)!=mp.end())
//             {
//                 return true;
//             }
//             mp[temp]=1;
//             temp=temp->next;
//         }
//         return false;
//     }
// };