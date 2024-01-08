class Solution {
public:
    string removeOuterParentheses(string s) {
        string temp="";
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
                temp+=ch;
                if(temp.size()>=2)
                {
                  ans+=ch;
                  
                }
            }
            else if(ch==')' && temp.size()!=1)
            {
                ans+=ch;
                temp.pop_back();
            }
            else 
            {
                temp.pop_back();
            }
        }
        return ans;
    }
};

//Other Method
// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//        stack<char>st;
//     string ans;
//     for(auto a:s)
//     {
//         if(a=='(')
//         {
//             if(st.size()>0)
//             {
//                 ans+='(';
//             }
//             st.push('(');
//         }
//         else
//         {
//             if(st.size()>1)
//             {
//                 ans+=')';
//             }
//             st.pop();
//         }
//     }
//     return ans;
//     }
// };