class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int start1=stoi(event1[0].substr(0,2))*60 +stoi(event1[0].substr(3,2));
        int end1=stoi(event1[1].substr(0,2))*60 +stoi(event1[1].substr(3,2));
        int start2=stoi(event2[0].substr(0,2))*60 +stoi(event2[0].substr(3,2));
        int end2=stoi(event2[1].substr(0,2))*60 +stoi(event2[1].substr(3,2));
        return (start1 <= end2 && start2 <= end1);

        
        
    }
};

// class Solution {
// public:


//     int cal(string a)
//     {
//         int ans = 0;
//         int d = 1;
//         for(int i=a.length()-1; i>=0; i--)
//         {
//             if(a[i]!=':')
//             {
//                 ans=ans+(a[i]-48)*d;
//                 d=d*10;
//             }
//         }
//         return ans;
//     }
    
//     bool haveConflict(vector<string>& event1, vector<string>& event2) {
    
//         if(cal(event2[0])<=cal(event1[1]) && cal(event2[1])>=cal(event1[0]))
//         {
//             return true;
//         }
//         return false;
//     }
// };