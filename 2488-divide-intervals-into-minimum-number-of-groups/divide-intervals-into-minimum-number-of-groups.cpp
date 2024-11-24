class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>range(1e6+2,0);
        int n=intervals.size();

        for(int i=0;i<n;i++)
        {
            int l=intervals[i][0];
            int r=intervals[i][1];
            range[l]++;
            range[r+1]--;
        }

        int maxCollision=0;
        for(int i=1;i<1e6+2;i++)
        {
            range[i]=range[i]+range[i-1];
            maxCollision=max(maxCollision,range[i]);
        }
        return maxCollision;

    }
};