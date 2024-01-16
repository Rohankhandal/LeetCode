class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lost_mp;  //key->player number , value -> no. of times he looses
        for(int i=0;i<matches.size();i++)
        {
            int loser=matches[i][1];
            lost_mp[loser]++;
        }

        vector<int>notLoss;
        vector<int>lostOnce;

        for(int i=0;i<matches.size();i++)
        {
            int winner=matches[i][0];
            int loss=matches[i][1];
            if(lost_mp.find(winner)==lost_mp.end())
            {
                notLoss.push_back(winner);
                //for not occur next time in notLoss vector,we push back the element in lost_mp 
                lost_mp[winner]=2;
            }
            if(lost_mp[loss]==1)
            {
                lostOnce.push_back(loss);
            }
        }

        //must be sorted
        sort(notLoss.begin(),notLoss.end());
        sort(lostOnce.begin(),lostOnce.end());

        return {notLoss,lostOnce};
    }
};