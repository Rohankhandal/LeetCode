/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* removeNthFromEnd(ListNode *head, int n)
        {
           	// Create two pointers, fastp and slowp
            ListNode *fastp = head;
            ListNode *slowp = head;

           	// Move the fastp pointer N nodes ahead
            for (int i = 0; i < n; i++)
                fastp = fastp->next;

           	// If fastp becomes NULL,
           	// the Nth node from the end is the head
            if (fastp == NULL)
                return head->next;

           	// Move both pointers until fastp reaches the end
            while (fastp->next != NULL)
            {
                fastp = fastp->next;
                slowp = slowp->next;
            }

           	// Delete the Nth node from the end
            ListNode *delNode = slowp->next;
            slowp->next = slowp->next->next;
            delete delNode;
            return head;
        }
};

//Time Complexity: O(L)+O(L-N), We are calculating the length of the linked list
// and then iterating up to the (L-N)th node of the linked list, where L is the total length of the list.

// Space Complexity:  O(1), as we have not used any extra space.
// class Solution
// {
//     public:
//         int getLength(ListNode *head)
//         {
//             int len = 0;
//             ListNode *temp = head;
//             while (temp != NULL)
//             {
//                 len++;
//                 temp = temp->next;
//             }
//             return len;
//         }
//     ListNode* removeNthFromEnd(ListNode *head, int n)
//     {
//         int len = getLength(head);
//         if (n == len)
//         {
//             ListNode *newhead = head->next;
//             delete(head);
//             return newhead;
//         }

//         int rem = len - n;
//         ListNode *temp = head;
//         while (temp != NULL)
//         {
//             rem--;
//             if (rem == 0)
//             {
//                 break;
//             }
//             temp = temp->next;
//         }
//        	// Delete the Nth node from the end
//         ListNode *delNode = temp->next;
//         temp->next = temp->next->next;
//         delete(delNode);
//         return head;
//     }
// };