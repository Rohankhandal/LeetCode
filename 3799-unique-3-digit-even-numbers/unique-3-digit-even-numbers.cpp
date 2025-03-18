class Solution {
public:
    void generateNumbers(vector<int>& digits, unordered_set<int>& st, int num, int count, vector<int>& freq) {
        if (count == 3) {
            if (num % 2 == 0) {
                st.insert(num);
            }
            return;
        }

        for (int i = 0; i < 10; i++) {
            if (freq[i] > 0) {
                // Ensure first digit is non-zero
                if (count == 0 && i == 0) continue; 

                freq[i]--;
                generateNumbers(digits, st, num * 10 + i, count + 1, freq);
                freq[i]++;
            }
        }
    }

    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;

        unordered_set<int> st;
        generateNumbers(digits, st, 0, 0, freq);
        
        return st.size();
    }
};
