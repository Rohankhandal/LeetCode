class Solution {
public:
    void solve(vector<bool>&visited,int &count,int pos,int n)
    {
        if(pos>n) count++;

        for(int i=1;i<=n;i++)
        {
            if(!visited[i] && (pos%i==0 || i%pos==0))
            {
             visited[i]=true;
             solve(visited,count,pos+1,n);
             visited[i]=false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool>visited(n+1,false);
        int count=0;
        int pos=1;
        solve(visited,count,pos,n);
        return count;
    }
};