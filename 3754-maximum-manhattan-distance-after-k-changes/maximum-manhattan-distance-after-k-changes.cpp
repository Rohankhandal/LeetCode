class Solution {
public:
    int maxDistance(string s, int k) {
        string temp=s;
        int n=s.size();
        int cnt=k;
        //go to north east -> as max you can go in east
        int x=0,y=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(temp[i]=='N') y++;
            else if(temp[i]=='E') x++;
            else if(cnt>0)
            {
                cnt--;
                x++;
            }
            else if(temp[i]=='W') x--;
            else if(temp[i]=='S') y--;
             ans=max(ans,abs(x)+abs(y));
        }


        cnt=k;
        x=0,y=0;
        //go to north west
        for(int i=0;i<n;i++)
        {
            if(temp[i]=='N') y++;
            else if(temp[i]=='W') x++;
            else if( cnt>0)
            {
                cnt--;
                x++;
            }
            else if(temp[i]=='E') x--;
            else if(temp[i]=='S') y--;
             ans=max(ans,abs(x)+abs(y));
        }
  

         cnt=k;
        x=0,y=0;
        //go to south east
        for(int i=0;i<n;i++)
        {
            if(temp[i]=='S') y++;
            else if(temp[i]=='E') x++;
            else if(cnt>0)
            {
                cnt--;
                x++;
            }
            else if(temp[i]=='N') y--;
            else if(temp[i]=='W') x--;
             ans=max(ans,abs(x)+abs(y));
        }
      

         cnt=k;
        x=0,y=0;
        //go to south west
        for(int i=0;i<n;i++)
        {
            if(temp[i]=='S') y++;
            else if(temp[i]=='W') x++;
            else if(cnt>0)
            {
                cnt--;
                x++;
            }
            else if(temp[i]=='N') y--;
            else if(temp[i]=='E') x--;
            ans=max(ans,abs(x)+abs(y));
        }
        


        return ans;
    }
};