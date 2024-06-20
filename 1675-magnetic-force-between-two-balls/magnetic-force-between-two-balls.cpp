class Solution {
public:
    bool isPossible(int mid,vector<int>&pos,int m)
    {
        int countBalls=1; //place first ball at 0th position
        int prevBall=pos[0];
        for(int i=1;i<pos.size();i++)
        {
            int currBall=pos[i];
            if(currBall-prevBall>=mid)
            {
                countBalls++;
                prevBall=currBall;
            }
            if(countBalls==m) break;
        }
        return countBalls==m;

    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
     sort(position.begin(),position.end());
     int l=1,r=position[n-1];
     int ans=0;
     while(l<=r)
     {
        int mid=(l+r)/2;
        if(isPossible(mid,position,m))
        {
            ans=mid;
            l=mid+1; //try for minimum distance must be maximum
        }
        else 
        {
            r=mid-1;
        }
     }
     return ans;
    }
};