class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>xorValue(n,0);
        xorValue[0]=arr[0];
        vector<int>ans;
        for(int i=1;i<n;i++)
        {
            xorValue[i]=arr[i]^xorValue[i-1];
        }

        for(auto &it:queries)
        {
            int l=it[0];
            int r=it[1];

            if(l==0) ans.push_back(xorValue[r]);
            else{
                int temp=xorValue[l-1]^xorValue[r];
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};