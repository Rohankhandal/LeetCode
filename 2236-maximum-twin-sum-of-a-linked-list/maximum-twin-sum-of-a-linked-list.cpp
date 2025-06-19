class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;

        while (temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        int ans = 0;
        int n = v.size();

        for (int i = 0; i < n / 2; i++) {
            int sum = v[i] + v[n - 1 - i];
            ans = max(ans, sum);
        }

        return ans;
    }
};
