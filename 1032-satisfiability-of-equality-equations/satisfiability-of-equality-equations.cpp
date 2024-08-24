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
            if(rank[x_parent]<rank[y_parent])
            {
                parent[x_parent]=y_parent;
            }
            else if(rank[x_parent]>rank[y_parent])
            {
                parent[y_parent]=x_parent;
            }
            else
            {
                parent[x_parent]=y_parent;
                rank[y_parent]++;
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);  //bcz lowercase is allow
        rank.resize(26,0);

        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }

        //first traverse equal case
        for(auto &str:equations)
        {
            if(str[1]=='=')
            {
                Union(str[0]-'a',str[3]-'a');
            }
        }

        //now traverse unequal case
        for(auto &str:equations)
        {
            if(str[1]=='!')
            {
                int parent_x=find(str[0]-'a');
                int parent_y=find(str[3]-'a');
                
                if(parent_x==parent_y) return false;
            }
        }

        return true;
    }
};