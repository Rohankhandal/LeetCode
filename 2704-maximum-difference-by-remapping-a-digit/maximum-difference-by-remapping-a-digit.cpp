class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        string maxValue=s;
        string minValue=s;

        int idx=-1;
        for(int i=0;i<s.size();i++)
        {
            if(idx==-1 && s[i]!='9')
            {
                idx=i;
            }

            if(idx!=-1 && s[i]==s[idx] )
            {
                maxValue[i]='9';
            }

        }


        idx=-1;
        for(int i=0;i<s.size();i++)
        {
            if(idx==-1 && s[i]!='0')
            {
                idx=i;
            }

            if(idx!=-1 && s[i]==s[idx] )
            {
                minValue[i]='0';
            }

        }


        int mini=stoi(minValue);
        int maxi=stoi(maxValue);
        cout<<maxValue<<" "<<minValue<<endl;
        return maxi-mini;
    }
};