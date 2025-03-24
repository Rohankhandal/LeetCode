class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int cnt=0;
        int s=1,e=1;
        sort(meetings.begin(),meetings.end());
        int i=0;
        while(i<meetings.size())
        {
            int start=meetings[i][0];
            int end=meetings[i][1];

            if(e<start)
            {
               if(i==0)
               {
                cnt+=(start-e);
               }
               else
               {
                cnt+=(start-e-1);
               }
                cout<<e<<" "<<start<<" "<<cnt<<endl;
                s=start;
                e=end;
            }
            else
            {
                e=max(e,end);
            }
            i++;
        }
        cnt+=days-e;
        return cnt;
    }
};