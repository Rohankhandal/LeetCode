class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int maxScore=0;
        int score=0;
        int l=0;
        int r=tokens.size()-1;
        while(l<=r)
        {
            if(tokens[l]<=power)
            {
                power-=tokens[l];
                l++;
                score++;
                 maxScore=max(score,maxScore);
            }
            else if(score>0)
            {
                power+=tokens[r--];
                score--;
            }
            else
            {
                 maxScore=max(score,maxScore);
                return maxScore;
            }

        }
        return maxScore;
    }
};