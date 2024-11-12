class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int val : asteroids) {
            // Handle collisions only when there are opposing directions
            bool destroyed = false;
            while (!st.empty() && val < 0 && st.top() > 0) {
                // Compare absolute values for collision results
                if (abs(st.top()) < abs(val)) {
                    st.pop();  // Top asteroid is smaller; it explodes
                } else if (abs(st.top()) == abs(val)) {
                    st.pop();  // Both are equal; both explode
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;  // Current asteroid is smaller; it explodes
                    break;
                }
            }
            // Only push the asteroid if it hasn't been destroyed
            if (!destroyed) {
                st.push(val);
            }
        }

        // Collect results from the stack
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }
        
        return ans;
    }
};