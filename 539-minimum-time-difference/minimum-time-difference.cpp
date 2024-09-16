class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>time;
        int n=timePoints.size();

        for(auto &s:timePoints)
        {
            int hour=stoi(s.substr(0,2));
            int minute=stoi(s.substr(3,2));

            int total=hour*60+minute;
            time.push_back(total);
        }
        sort(time.begin(),time.end());

        int minDiff=INT_MAX;
        for(int i=1;i<n;i++)
        {
            minDiff=min(minDiff,time[i]-time[i-1]);
        }

        int lastDiff=abs(time[n-1]-(24*60+time[0]));
        minDiff=min(lastDiff,minDiff);
        return minDiff;
    }
};