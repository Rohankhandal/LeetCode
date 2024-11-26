class Solution {
public:
    
    int findChampion(int n, vector<vector<int>>& edges) {
        int ans=0;
        vector<bool>visited(n,false);
        vector<int>inDegree(n,0);
        for(auto &it:edges)
        {
            int u=it[0];
            int v=it[1];
            inDegree[v]++;
        }

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0) 
            {
                ans=i; cnt++;
            }
            if(cnt==2) return -1;
        }
        return ans;
        
        return ans;
    }
};