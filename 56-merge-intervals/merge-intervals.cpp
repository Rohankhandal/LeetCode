class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int start=intervals[0][0];
        int end=intervals[0][1];

        for(int i=1;i<n;i++)
        {
            int s=intervals[i][0];
            int e=intervals[i][1];

            if(s<=end)
            {
                end=max(e,end);
            }
            else
            {
                ans.push_back({start,end});
                start=s;
                end=e;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};