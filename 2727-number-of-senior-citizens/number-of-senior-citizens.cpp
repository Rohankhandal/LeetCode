class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int ans=0;
        for(auto &str:details)
        {
            int first=str[11]-'0';
            int second=str[12]-'0';
            int age=first*10+second;
            // cout<<age<<endl;
            if(age>60) ans++;
        }
        return ans;
    }
};