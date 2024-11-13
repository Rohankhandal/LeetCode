class Solution {
public:
    bool rotateString(string s, string goal) {
        int len1=s.size();
        int len2=goal.size();

        if(len1!=len2) return false;
        if(s==goal) return true;
        for(int i=1;i<len1;i++)  //rotate i times
        {
            string temp=s;
            for(int idx=0;idx<len1;idx++){
                temp[idx]=s[(idx+i)%len1];
            }

            if(temp==goal) return true;

        }
        return false;
    }
};



// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(s.size()>goal.size()) return false;
//         string newStr=s+s;
//         if(newStr.find(goal)!=string::npos)
//         {
//             return true;
//         }
//         return false;
//     }
// };