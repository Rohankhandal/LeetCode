class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,int dist,int src,int k,int &ans,int parent)
    {
        if(dist>k) return ;
        ans++;

        for(auto &v:adj[src])
        {
            if(v!=parent)
            {
                dfs(adj,dist+1,v,k,ans,src);
            }
        }
    
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size();
        int m=edges2.size();
        vector<int>dist1(n+1,0);
        vector<int>dist2(m+1,0);
        vector<int>ans;

        unordered_map<int,vector<int>>adj1;
        unordered_map<int,vector<int>>adj2;

        for(auto &e:edges1)
        {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for(auto &e:edges2)
        {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        for(int i=0;i<n+1;i++)
        {
            int dist=0;
            int ans=0;
            dfs(adj1,dist,i,k,ans,-1);
            dist1[i]=ans;
            cout<<ans<<" ";
        }
        cout<<endl;

        for(int i=0;i<m+1;i++)
        {
            int dist=0;
            int ans=0;
            dfs(adj2,dist,i,k-1,ans,-1);
            dist2[i]=ans;
            cout<<ans<<" ";
        }
        int max2=*max_element(dist2.begin(),dist2.end());

        for(int i=0;i<n+1;i++)
        {
            ans.push_back(dist1[i]+max2);
        }
        return ans;

    }
};