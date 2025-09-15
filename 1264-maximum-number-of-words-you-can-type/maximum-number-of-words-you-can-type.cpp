class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int>mp;
        for(auto &it:brokenLetters){
            mp[it]++;
        }
        int ans=0;
        stringstream ss(text);
        string temp;
        while(ss>>temp){
            bool flag=true;
            for(auto &s:temp){
                if(mp.find(s)!=mp.end()){
                    flag=false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
    
};