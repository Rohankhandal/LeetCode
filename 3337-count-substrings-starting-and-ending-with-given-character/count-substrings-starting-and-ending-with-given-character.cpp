class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n=s.size();
        long long  freq=0;
        for(auto &it:s) 
        {
            if(it==c) freq++;
        }
        long long ans=freq*(freq+1)/2;
        return ans ;
    }
};