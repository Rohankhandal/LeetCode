class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hCut, vector<int>& vCut) {
        priority_queue<pair<int,char>>pq;
        for(auto &it:hCut)
        {
            pq.push({it,'H'});
        }

        for(auto &it:vCut)
        {
            pq.push({it,'V'});
        }

        int ans=0;
        int h=1,v=1;
        while(!pq.empty())
        {
            int cost=pq.top().first;
            char cut=pq.top().second;
            pq.pop();

            if(cut=='V')
            {
                h++;
                ans+=(v*cost);
            }
            else
            {
                v++;
                ans+=(h*cost);
            }
        }
        return ans;

        

        
    }
};