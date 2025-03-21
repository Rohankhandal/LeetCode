class Solution {
public:
    vector<string> f(unordered_map<string , vector<string>>&adj,unordered_map<string,int>&inorder,int src
    )
    {
        queue<string>q;
        vector<string>ans;
        for(auto &it:inorder)
        {
            if(it.second==0)
            {
                q.push(it.first);
            }
        }

        while(!q.empty())
        {
            string temp=q.front();
            q.pop();

            for(auto &it:adj[temp])
            {
                inorder[it]--;
                if(inorder[it]==0)
                {
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string , vector<string>>adj;
        unordered_map<string,int>inorder;

        for(int i=0;i<recipes.size();i++)
        {
            for(auto &in:ingredients[i])
            {
                adj[in].push_back(recipes[i]);
                inorder[recipes[i]]++;
            }
        }
        for(auto &it:supplies)
        {
            inorder[it]=0;
        }

        return f(adj,inorder,0);

    }
};