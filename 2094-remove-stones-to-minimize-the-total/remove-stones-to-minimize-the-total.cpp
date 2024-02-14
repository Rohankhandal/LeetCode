class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>mp;
        for(int i=0;i<piles.size();i++)
        {
            mp.push(piles[i]);
        }
        for(int i=0;i<k;i++)
        {
            int top=mp.top();
            mp.pop();
            mp.push(ceil(static_cast<double>(top)/2));
        }
        int sum=0;
        while(!mp.empty())
        {
            sum+=mp.top();
            mp.pop();
        }
        return sum;
    }
};