class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
     int n=customers.size();
     int start=customers[0][0];
     int needTime=customers[0][1];
        
     double ans=0;
     int totalTime=0;
     totalTime+=(start+needTime);
            
    int time=(start+needTime)-start;
    ans+=time;
        
        for(int i=1;i<n;i++)
        {   
            start=customers[i][0];
            needTime=customers[i][1];
            if(start>totalTime)
            {
                totalTime=totalTime+(start-totalTime)+needTime;
            }
            else
            {
                totalTime=totalTime+needTime;
            }
            
            ans+=(totalTime)-start;
        }
        return (double)ans/n;
    }
};