// 1.sort the array according to end day
// 2.pick the nearest day avaiable
// (Greedy Method)

class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)  //we must have to sort data according to end time bcz 
    //if last end time come early then nearest days is used 
    //e.g [[1,2],[1,2],[3,3],[1,5],[1,5]]
    //after sort according to first day
        // 1 2
        // 1 2
        // 1 5
        // 1 5
        // 3 3
    {
        if(a[1]<b[1]) return true;
        else if(a[1]==b[1]) return a[0]<b[0];
        return false;
    }
    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(),events.end(),cmp);
        // for(int i=0;i<events.size();i++)
        // {
        //    cout<<events[i][0]<<" "<<events[i][1]<<endl;
        // }
        int cnt=0;
        set<int>days;
        for(int i=1;i<=100000;i++)  days.insert(i);

        for(auto &event:events)
        {
            int s=event[0];int e=event[1];
            auto it=days.lower_bound(s);
            if(it == days.end() || *it>e)
            {
                continue;
            }
            else
            {
                ++cnt;
                days.erase(it);
            }

        }
        return cnt;

    }
};