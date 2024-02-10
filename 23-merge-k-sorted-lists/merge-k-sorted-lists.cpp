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
//Better approach using priority queue
// T.C:-k*logK +N*K*logK
// S.c:-O(K)
// add or access in priority queue take logK
// k=lists.size()
// N=total no.of elements in lists
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,
        greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])   //check first node every LL is NULL or not
            {
                pq.push({lists[i]->val,lists[i]});
            }
        }

        ListNode *dummyNode=new ListNode(-1);
        ListNode *temp=dummyNode;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            if(it.second -> next)
            {
                pq.push({it.second->next->val,it.second->next});
            }
            temp->next=it.second;
            temp=temp->next;
        }
        return dummyNode->next;
    }
};


//  T.C:-N1+(N1+N2) +(N1+N2+N3) + (N1+N2+N3+N4) + ........
        // SUPPOSE N=N1,N2,N3.....
        // SO, N+2N+3N+4N+......
        // N(1+2+3+4......K)
        // N(K*(K+1)/2)
        // NEARLY o(N^2)
// class Solution {
// public:
// ListNode* merge(ListNode* l1,ListNode* l2)
// {
//     if(l1==NULL)
//     {
//         return l2;
//     }
//     if(l2==NULL)
//     {
//         return l1;
//     }
//     ListNode* dummyNode=new ListNode(-1);
//     ListNode* ansPtr=dummyNode;
//     while(l1!=NULL && l2!=NULL)
//     {
//         if(l1->val < l2->val)
//         {
//             ansPtr->next=l1;
//             ansPtr=l1;
//             l1=l1->next;
            
//         }
//         else {
//             ansPtr->next=l2;
//             ansPtr=l2;
//             l2=l2->next;
            
//         }
//     }
//     if(l1)
//     {
//         ansPtr->next=l1;
//     }
//     if(l2)
//     {
//         ansPtr->next=l2;
//     }
//     return dummyNode->next;

// }
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int n=lists.size();
//         if(n==0)
//         {
//             return NULL;
//         }
//         if(n==1)
//         {
//             return lists[0];
//         }
//         ListNode *head=lists[0];
//         for(int i=1;i<lists.size();i++)
//         {
//             head=merge(head,lists[i]);
//         }
//         return head;
//     }
// };