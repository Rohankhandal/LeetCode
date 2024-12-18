class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>freq(26,0);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }

        string ans="";
        for(int i=25;i>=0;)
        {
            if(freq[i]>0)
            {
                int use=min(repeatLimit,freq[i]);
                freq[i]-=use;
                ans+=string(use,'a'+i);

                if(freq[i]>0) //find for next smaller element
                {
                    int j=i;
                    j--;
                    while(j>=0 && freq[j]==0)
                    {
                        j--;
                    }

                    if(j<0) //not found
                    {
                        break;
                    }
                    else
                    {
                        ans+=string(1,'a'+j);
                        freq[j]--;
                    }
                }
                else
                {
                    i--;
                }
            }
            else
            {
                i--;
            }
        }
        return ans;


    }
};