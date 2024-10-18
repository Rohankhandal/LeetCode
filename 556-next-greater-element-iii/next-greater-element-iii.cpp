class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);

        int sz=s.size();
        bool flag=false;
        int idx=0;
        // Find the first digit from the right that is smaller than the next digit
        for (int i = sz - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                flag = true;
                idx = i;
                break;          // Break when the first smaller element is found
            }
        }

        if (!flag) return -1;    // If no such digit is found, return -1
        
        // Find the smallest element larger than s[idx] from the right side
        int j = 0;
        for (j = sz - 1; j > idx; j--) {
            if (s[j] > s[idx]) {
                break;
            }
        }

        // Swap the two elements
        swap(s[idx], s[j]);
        
        // Reverse the elements to the right of idx to get the next permutation
        reverse(s.begin() + idx + 1, s.end());

        // Convert the string back to a number
        long long temp = stoll(s);
        
        // If the number exceeds INT_MAX, return -1, otherwise return the number
        if (temp > INT_MAX) return -1;
        else return temp;
    }
};