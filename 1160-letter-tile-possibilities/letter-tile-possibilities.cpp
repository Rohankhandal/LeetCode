class Solution {
public:
    int solve(vector<int>&freq)
    {
        int ways=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0){
                freq[i]--;
                ways+=1+solve(freq);
                freq[i]++;
            }
        }
        return ways;
    }
    int numTilePossibilities(string tiles) {
        vector<int>freq(26,0);
        for(auto &c:tiles) freq[c-'A']++;
        return solve(freq);
    }
};