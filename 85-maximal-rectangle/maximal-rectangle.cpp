class Solution {
public:
    // Find Next Smaller Element to Right - returns array of indices
    // For each element, find the first smaller element to its right
    vector<int> NSR(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = n;  // Used when no smaller element exists to right
        vector<int> right(n);
        
        for(int i = n-1; i >= 0; i--) {
            // If stack is empty, no smaller element exists to right
            if(st.empty()) {
                right[i] = pseudo_index;
            } else {
                // Pop elements from stack until we find a smaller element
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                right[i] = st.empty() ? pseudo_index : st.top();
            }
            st.push(i);  // Push current index to stack
        }
        return right;
    }

    // Find Next Smaller Element to Left - returns array of indices
    // For each element, find the first smaller element to its left
    vector<int> NSL(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = -1;  // Used when no smaller element exists to left
        vector<int> left(n);
        
        for(int i = 0; i < n; i++) {
            // If stack is empty, no smaller element exists to left
            if(st.empty()) {
                left[i] = pseudo_index;
            } else {
                // Pop elements from stack until we find a smaller element
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                left[i] = st.empty() ? pseudo_index : st.top();
            }
            st.push(i);  // Push current index to stack
        }
        return left;
    }
    
    // Calculate Maximum Area in Histogram
    int MAH(vector<int>& heights) {
        int n = heights.size();
        
        // Get indices of next smaller elements on both sides
        vector<int> right = NSR(heights);  // Next smaller to right
        vector<int> left = NSL(heights);   // Next smaller to left
        
        // Calculate width for each bar
        // Width = (right boundary - left boundary - 1)
        vector<int> width(n);
        for(int i = 0; i < n; i++)
            width[i] = right[i] - left[i] - 1;
        
        // Calculate area for each bar and track maximum
        int max_area = 0;
        for(int i = 0; i < n; i++) {
            int area = width[i] * heights[i];
            max_area = max(max_area, area);
        }
        return max_area;
    }
    
    // Main function to find maximal rectangle in binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Initialize height array for first row
        vector<int> height(cols);
        for(int j = 0; j < cols; j++) {
            height[j] = (matrix[0][j] == '1') ? 1 : 0;
        }
        
        // Calculate initial maximum area using first row
        int maxArea = MAH(height);
        
        // Process subsequent rows
        for(int i = 1; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                // If current cell is '0', reset height to 0
                // If current cell is '1', add 1 to previous height
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            // Calculate maximum area for current histogram
            maxArea = max(maxArea, MAH(height));
        }
        
        return maxArea;
    }
};