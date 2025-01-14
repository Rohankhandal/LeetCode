class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        int n=A.size();
        int same=0;

        for(int i=0;i<n;i++)
        {
            mp1[A[i]]++;
            int same=0;
            for(int j=0;j<=i;j++)
            {
                if(mp1.find(B[j])!=mp1.end())
                {
                    same++;
                }
            }
           
            ans.push_back(same);
        }
        return ans;
    }
};