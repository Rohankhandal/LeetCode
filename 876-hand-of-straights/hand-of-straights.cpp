class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        int n=hand.size();
        if(n%groupSize!=0) return false;
        for(auto &it:hand)
        {
            mp[it]++;
        }
        vector<int>ans;
        int group=0;
        int count=0;
        while(!mp.empty())
        {
            int prev=-1;
            int count=0;
            for(auto it=mp.begin();it!=mp.end();it++)
            {
           
                cout<<it->first<<endl;
                if(prev==-1)
                {
                    prev=it->first;
                }
                else
                {
                    if(prev+1==it->first)
                    {
                        prev=it->first;
                    }
                    else
                    {
                        return false;
                    }
                }

                count++;
                it->second--;
                if(it->second==0)
                    mp.erase(it);

                if(count==groupSize)
                {
                    group++;
                    break;
                } 
            }
            if(count!=groupSize) return false;
        }
        return n/groupSize==group?true:false;
        

    }
};