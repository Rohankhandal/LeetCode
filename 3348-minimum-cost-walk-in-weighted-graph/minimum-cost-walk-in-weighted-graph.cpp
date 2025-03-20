class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    void Union(int x,int y)
    {
        int parent_x=find(x);
        int parent_y=find(y);

        if(parent_x==parent_y) return ;

        if(rank[parent_x]<rank[parent_y])
        {
            parent[parent_x]=parent_y;
        }
        else if(rank[parent_x]>rank[parent_y])
        {
            parent[parent_y]=parent_x;
        }
        else
        {
            rank[parent_x]++;
            parent[parent_y]=parent_x;
        }
    }

    int find(int x)
    {
        if(parent[x]==x) return x;

        return parent[x]=find(parent[x]);
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int>ans;
        parent.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        rank.resize(n,1);

        for(auto &it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            Union(u,v);
        }

        unordered_map<int,int>mp;
        for(auto &it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            int root=find(u);

             if (mp.find(root) == mp.end()) {
                mp[root] = wt;
            } else {
                mp[root] = mp[root]&wt;
            }
        }
        
        // for(auto &it:mp)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        for(auto &q:query)
        {
            int l=q[0];
            int r=q[1];

            if(find(l)==find(r))
            {
                ans.push_back(mp[find(l)]);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};