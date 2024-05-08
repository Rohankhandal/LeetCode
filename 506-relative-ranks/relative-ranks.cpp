class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        unordered_map<int,string>mp;
        unordered_map<int,int>index;
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(score[i]);
            index[score[i]]=i;
        }
        int count=1;
        while(!pq.empty())
        {
            int val=pq.top();
            pq.pop();
            if(count==1)
            {
                mp[val]="Gold Medal";
            }
            else if(count==2)
            {
                mp[val]="Silver Medal";
            }
            else if(count==3)
            {
                mp[val]="Bronze Medal";
            }
            else
            {
                mp[val]=to_string(count);
            }
            count++;
        }


        vector<string>ans(n);
        for(auto &it:mp)
        {
            ans[index[it.first]]=it.second;
        }
        return ans;
    }
};