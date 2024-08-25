class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int num)
    {
        if(num==parent[num]) return num;

        return parent[num]=find(parent[num]);
    }

    void Union(int x,int y)
    {
        int x_parent=find(x);
        int y_parent=find(y);

        if(x_parent!=y_parent)
        {
            if(rank[x_parent]>rank[y_parent])
            {
                parent[y_parent]=x_parent;
            }
            else if(rank[x_parent]<rank[y_parent])
            {
                parent[x_parent]=y_parent;
            
            }
            else
            {
                parent[x_parent]=y_parent;
                rank[y_parent]++;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {

        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int components=n;  //no. of edges

        if(connections.size()<n-1) return -1;
        for(auto &it:connections)
        {
            int parent_x=find(it[0]);
            int parent_y=find(it[1]);

            if(parent_x!=parent_y)
            {
                Union(it[0],it[1]);
                components--;
            }
        }

        return components-1;
    }
};