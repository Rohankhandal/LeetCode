class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>freeTime;
        int end=0;
        for(int i=0;i<n;i++)
        {
            int dist=startTime[i]-end;
            freeTime.push_back(dist);

            end=endTime[i];
        }
         int dist=eventTime-endTime[n-1];
         freeTime.push_back(dist);

        // for(auto &it:freeTime)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        int ans=0;
        int sum=0;
        for(int i=0;i<k+1 && i<freeTime.size();i++)
        {
            sum+=freeTime[i];
        }
        ans=max(sum,ans);

        int j=0;
        for(int i=k+1;i<freeTime.size();i++)
        {
            sum-=freeTime[j];
            sum+=freeTime[i];
            j++;

            ans=max(ans,sum);
        }
        return ans;
    }
};