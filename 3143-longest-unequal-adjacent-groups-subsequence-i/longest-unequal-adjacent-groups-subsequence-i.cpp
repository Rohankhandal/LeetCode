class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
         vector<string>ans;
         int n=words.size();
        int i=0,j=1;
        ans.push_back(words[i]);
        while(j<n){
            if(groups[i]!=groups[j]){
                ans.push_back(words[j]);
                i=j;
            }
            j++;
        }
        return ans;
    }
};