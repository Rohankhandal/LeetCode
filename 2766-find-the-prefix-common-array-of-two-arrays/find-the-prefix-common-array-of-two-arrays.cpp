class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        unordered_map<int,int>mp;
       
        int n=A.size();
        int same=0;

        for(int i=0;i<n;i++)
        {
            mp[A[i]]++;
            if(mp[A[i]]==2) same++;
            mp[B[i]]++;
             if(mp[B[i]]==2) same++;

            ans.push_back(same);
        }
        return ans;
    }
};