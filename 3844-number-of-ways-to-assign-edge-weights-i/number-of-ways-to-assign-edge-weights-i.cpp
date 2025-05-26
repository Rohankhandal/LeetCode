class Solution {
public:
    int MOD=1e9+7;
    int findPow(long long  x,int n)
    {
        long long ans=1;
        while(n>0)
        {
            if(n&1)
            {
                ans=(ans*x)%MOD;
            }

            x=(x*x)%MOD;
            n>>=1;
        }
        return ans;
    }
    void dfs(int src,int parent,unordered_map<int,vector<int>>&adj,int &maxDepth,int h)
    {
        maxDepth=max(h,maxDepth);

        for(auto &v:adj[src])
        {
            if(v!=parent)
            {
                dfs(v,src,adj,maxDepth,h+1);
            }
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
      unordered_map<int,vector<int>>adj;
      for(auto &e:edges)
      {
         adj[e[0]].push_back(e[1]);
         adj[e[1]].push_back(e[0]);
      }   

      //find maxDepth 
      int maxDepth=0;
      dfs(1,-1,adj,maxDepth,0);

     
      int res=findPow(2,maxDepth-1);
    //   for(int i=1;i<maxDepth;i++)
    //   {
    //      res=(res*2)%MOD;
    //   }
      return res;
    }
};