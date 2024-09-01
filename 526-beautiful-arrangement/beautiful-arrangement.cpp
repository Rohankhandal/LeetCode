class Solution {
public:
    void solve(vector<bool>&visited,int &ans,int n,int currNum)
    {
        if(currNum==n+1)
        {
            ans++;
            return ;
        }

        for(int i=1;i<=n;i++){  //place every value 
            if(visited[i]==false && (currNum%i==0 || i%currNum==0))
            {
                visited[i]=true;
                solve(visited,ans,n,currNum+1);
                visited[i]=false;  //backtracking
            }
        }
    }
    int countArrangement(int n) {
        vector<bool>visited(n+1,false);
        int ans=0;
        solve(visited,ans,n,1);
        return ans;
    }
};