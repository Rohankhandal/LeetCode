//Approach (Using stringstream tokenizer in C++)
//T.C : O(m+n)
//S.C : O(m+n)
class Solution {
public:
    vector<string> getTokens(string version) {
        stringstream v(version);
        string token_v = "";
        vector<string> version_tokens;
        while(getline(v, token_v, '.')) {  //automatically break when string end
            version_tokens.push_back(token_v);
        }
        return version_tokens;
    }
    int compareVersion(string version1, string version2) {

        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);  
        
        int m = v1.size();
        int n = v2.size();
            
        int  i = 0;
        while(i < m || i < n) {
            
            int a = i < m ? stoi(v1[i]) : 0 ;
            int b = i < n ? stoi(v2[i])  : 0 ;
            
            if(a > b)
                return 1;
            else if(b > a)
                return -1;
            else
                i++;
        }
        return 0;
    }
};









// class Solution {
// public:
//     int compareVersion(string ver1, string ver2) {
        
//         int n1=ver1.size();
//         int n2=ver2.size();
//         int i=0,j=0;
//         while(i<n1 && j<n2)
//         {
//             long long num1=0,num2=0;
//             while(i<n1 && ver1[i]!='.')
//             {
//                 num1=num1*10+(ver1[i]-'0');
//                 i++;
//             }
//             while(j<n2&&ver2[j]!='.')
//             {
//                 num2=num2*10+(ver2[j]-'0');
//                 j++;
//             }
//             if(num1>num2)
//             {
//                 return 1;
//             }
//             else if(num1<num2)
//             {
//                 return -1;
//             }
//             i++;
//             j++;
//         }
//         while(i<n1)
//         {
//             long long num1=0;
//            while(i<n1 && ver1[i]!='.')
//             {
//                 num1=num1*10+(ver1[i]-'0');
//                 i++;
//             }
//             if(num1!=0) return 1;
//             i++;
//         }
//         while(j<n2)
//         {
//             long long num2=0;
//            while(j<n2&&ver2[j]!='.')
//             {
//                 num2=num2*10+(ver2[j]-'0');
//                 j++;
//             }
//             if(num2!=0) return -1;
//             j++;
//         }
//         return 0;
//     }
// };