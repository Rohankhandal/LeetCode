class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=i+j;
                mp[sum].push_back(mat[i][j]);
            }
        }

        for(auto &it:mp)
        {
            int sum=it.first;
            if(sum&1){
                vector<int>temp=it.second;
                for(auto &ele:temp){
                    ans.push_back(ele);
                }
            }
            else{
                 vector<int>temp=it.second;
                 reverse(temp.begin(),temp.end());
                for(auto &ele:temp){
                    ans.push_back(ele);
                }
            }
        }
        return ans;
    }
};