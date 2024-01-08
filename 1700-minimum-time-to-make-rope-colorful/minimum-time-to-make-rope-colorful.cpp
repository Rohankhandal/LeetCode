class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mini=0;
        int n=colors.size();
        for(int i=0;i<n-1;i++)
        {
            if(colors[i]==colors[i+1])
            {
                mini+=min(neededTime[i],neededTime[i+1]);
                neededTime[i+1]=max(neededTime[i],neededTime[i+1]);   //imp part
            }
        }
    return mini;
    }
};

// Which one balloon out of thennn balloons should we not remove?
// The one with maximum neededTime[i].