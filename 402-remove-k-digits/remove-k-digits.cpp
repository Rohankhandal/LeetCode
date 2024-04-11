//Using simple Monotonic Nature of Numbers
//T.C : O(n)
//S.C : O(1) - I am ignoring the space taken for result variable
// class Solution {
// public:
//     string removeKdigits(string num, int k) {
        
//         string result = ""; //it will act like a stack
//         int n = num.length();
        
//         for(int i = 0; i < n; i++) {
            
//             while(result.length() > 0 && result.back() > num[i] && k > 0) {
//                 result.pop_back();
//                 k--;
//             }
            
//             if(result.length() > 0 || num[i] != '0') {     //GOOD CONDITION
//                 result.push_back(num[i]); //to avoid the case when we have preceeding zeros
//             }
            
//         }
        
        
//         while(result.length() > 0 && k > 0) {
//             result.pop_back();
//             k--;
//         }

//         if(result == "") {
//             return "0";
//         }
        
//         return result;
        
//     }
// };

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        int i=0;
        while(i<num.size())
        {
            while(ans.size()>0 && ans.back()>num[i] && k)
            {
                ans.pop_back();
                k--;

            }
            ans.push_back(num[i]);
            i++;
        }
        
        while(ans.size()>0 && k)
        {
            ans.pop_back();
            k--;
        }
        //we have to deal with preceding zeros in answer
        string result="";
        i=0;
        while(ans[i]=='0')
        {
            i++;
        }
        
        result=ans.substr(i,ans.size());
        
        if(result=="") return "0";

        return result;
    }
};