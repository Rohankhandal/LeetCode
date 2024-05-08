class Solution {
public:  //T.c:-O(N) S.C:_(O(maxElement))
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();

        int M=*max_element(score.begin(),score.end());
        vector<int>mp(M+1,-1);
        for(int i=0;i<n;i++)
        {
            mp[score[i]]=i;
        }
        vector<string>result(n);
        int rank=1;
        for(int s=M;s>=0;s--)
        {
            if(mp[s]!=-1)
            {
                int ath=mp[s];
                if(rank==1)
                {
                    result[ath]="Gold Medal";
                }else if(rank==2)
                {
                    result[ath]="Silver Medal";
                }else if(rank==3)
                {
                    result[ath]="Bronze Medal";
                }
                else
                {
                    result[ath]=to_string(rank);
                }
                rank++;
            }
        }
        return result;
    }
};