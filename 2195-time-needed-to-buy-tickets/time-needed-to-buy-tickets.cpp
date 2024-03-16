class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int needTicket=tickets[k];
        int n=tickets.size();
        int time=0;
        for(int i=0;i<=k;i++)
        {
            if(tickets[i]>=needTicket)
            {
                time+=needTicket;
            }
            else
            {
                time+=tickets[i];
            }
        }
        for(int i=k+1;i<n;i++)
        {
            if(tickets[i]>=needTicket)
            {
                time+=needTicket-1;
            }
            else
            {
                time+=tickets[i];
            }
        }
        return time;
    }
};