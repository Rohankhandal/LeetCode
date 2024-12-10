class Solution {
public:
     static bool cmp(vector<int>&a,vector<int>&b){
           if(a[0]==b[0])return a[1]<b[1];
           return a[0]<b[0];
     }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),cmp);
        int n=events.size(),ans=0,temp=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<n;i++){      

            while(!q.empty() && q.top().first<events[i][0]){
                temp=max(temp,q.top().second);
                q.pop();
            }

            ans=max(ans,events[i][2]+temp);
            q.push({events[i][1],events[i][2]});
        }
        return ans;
    }
};