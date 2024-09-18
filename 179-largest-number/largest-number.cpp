//T.C : O(nlogn)
//S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
class Solution {
public:
    static bool myFunction(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);

        return (s1+s2)>(s2+s1);   //IMP
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), myFunction);
        
        
        if(nums[0] == 0)
            return "0";
        string result = "";
        for(int i:nums)
            result += to_string(i);
        return result;
        
    }
};






// class Solution {
// public:
//     static bool mycomp(string a, string b)
//     {
//         //desceding order compartor
//         //return a>b;  
        

//         //if a=3 and b= 30 then in string sorting 30 is greater than 3 but 
//         //in real screnrio 303 is not greater number from 330
//         string t1 = a+b;
//         string t2= b+a;
//         return t1>t2; //if true then first return a then return b
//     }

//     string largestNumber(vector<int>& nums) {
//         vector<string> snums;
//         for(auto n:nums)
//         {
//             snums.push_back(to_string(n));
//         }

//         sort(snums.begin(),snums.end(),mycomp);

//         if(snums[0] == "0")   return "0";     //special case come from test case;

//         string ans="";
//         for(auto str:snums)
//         {
//             ans+=str;
//         }
//         return ans;
//     }
// };