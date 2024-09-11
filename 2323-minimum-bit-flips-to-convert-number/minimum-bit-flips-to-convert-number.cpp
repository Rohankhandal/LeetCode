class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        while(start || goal)
        {
            int first=start&1;
            int second=goal&1;

            if(first!=second) cnt++;

            start>>=1;
            goal>>=1;
        }
        return cnt;
    }
};