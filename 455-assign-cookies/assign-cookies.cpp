class Solution {
public:
    int solve(vector<int>& g, vector<int>& s,int i,int j)
    {
        if(i>=g.size()) return 0;
        if(j>=s.size()) return 0;
        
        int op1=0;
        int op2=0;
        if(g[i]<=s[j])
        {
            op1=1+solve(g,s,i+1,j+1);
        }
        else
        {
            op2=0+solve(g,s,i,j+1);
        }
        return op1+op2;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        return solve(g,s,0,0);
        
    }
};