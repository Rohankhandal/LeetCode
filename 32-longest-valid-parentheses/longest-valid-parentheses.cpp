class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0,close=0;
        int maxi=0;
        int n=s.size();

        //0...n
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
                open++;
            }
            else
            {
                close++;
            }

            if(open==close)
            {
                int len=open+close;
                maxi=max(len,maxi);
            }
            else if(close>open)
            {
                open=0;close=0;
            }
        }

          //For remove problem when open>close e.g:-')()(()()(' 
        //Right to left 
        //n...0
       open=0,close=0;
        for(int i=n-1;i>=0;i--)
        {
            char ch=s[i];
            if(ch=='(')
            {
                open++;
            }
            else
            {
                close++;
            }

            if(open==close)
            {
                int len=open+close;
                maxi=max(len,maxi);
            }
            else if(open>close)
            {
                open=0;close=0;
            }
        }

        return maxi;

    }
};




//T.c:-O(N)
//S.c:-O(N)

// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         // Stack to store indices of parentheses
//         // Initialize with -1 to handle edge case when first char is ')'
//         stack<int> st;
//         st.push(-1);
        
//         // Track the maximum length of valid parentheses substring
//         int maxLen = 0;
        
//         // Iterate through each character in the string
//         for(int i = 0; i < s.length(); i++) {
//             char ch = s[i];
            
//             if(ch == '(') {
//                 // For opening bracket, push its index onto stack
//                 st.push(i);
//             } else {
//                 // For closing bracket:
//                 // 1. Pop the top element (matching opening bracket or base index)
//                 st.pop();
                
//                 if(st.empty()) {
//                     // If stack becomes empty, push current index as new base
//                     // This handles cases where we have extra closing brackets
//                     st.push(i);
//                 } else {
//                     // Calculate length of valid substring:
//                     // Current index - index at top of stack
//                     int len = i - st.top();
//                     maxLen = max(len, maxLen);
//                 }
//             }
//         }
        
//         return maxLen;
//     }
// };