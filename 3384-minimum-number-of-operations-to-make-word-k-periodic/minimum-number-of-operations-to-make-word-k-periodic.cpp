class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n=word.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i+=k)
        {
            string str=word.substr(i,k);
            // cout<<str<<endl;
            mp[str]++;
        }
        int maxi=INT_MIN;
        for(auto &it:mp)
        {
            maxi=max(maxi,it.second);
        }

        return word.size()/k-maxi;
    }
};