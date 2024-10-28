class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;  // Vector to store the result
        stack<pair<int,int>>st;  // Stack stores {temperature, count} pairs
        int n = temperatures.size();
        
        // Process from right to left
        for(int i = n-1; i >= 0; i--) {
            // If stack is empty, no warmer day ahead
            if(st.empty()) {
                ans.push_back(0);
                st.push({temperatures[i], 1});  // Push current temp with count 1
            }
            else {
                int cnt = 1;  // Initialize count for current temperature
                
                // While we find temperatures <= current temperature
                // Add their counts to get total days to next warmer temperature
                while(!st.empty() && st.top().first <= temperatures[i]) {
                    cnt += st.top().second;  // Add the count from stack top
                    st.pop();  // Remove the smaller/equal temperature
                }
                
                // If stack becomes empty, no warmer day ahead
                if(st.empty()) {
                    ans.push_back(0);
                    st.push({temperatures[i], 1});
                }
                else {
                    // Found a warmer day, push the count of days
                    ans.push_back(cnt);
                    // Push current temperature with its count
                    st.push({temperatures[i], cnt});
                }
            }
        }

        // Since we processed right to left, reverse to get correct order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};