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
    // Function to reverse the linked list
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        if (!head) return {};

        // Reverse the linked list
        head = reverseLL(head);

        // Stack to keep track of next larger nodes
        stack<int> st;
        vector<int> result;

        ListNode* temp = head;
        while (temp != nullptr) {
            while (!st.empty() && st.top() <= temp->val) {
                st.pop();
            }
            if (st.empty()) {
                result.push_back(0);
            } else {
                result.push_back(st.top());
            }
            st.push(temp->val);
            temp = temp->next;
        }

        // Reverse the result to match the original order
        reverse(result.begin(),result.end());

        // Reverse the linked list back to original order (optional)
        head = reverseLL(head);

        return result;
    }
};
