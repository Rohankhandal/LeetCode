class Solution {
public:
    void getrightMax(vector<int>&height,vector<int>&maxi)
    {
        int n=height.size();
        maxi[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxi[i]=max(maxi[i+1],height[i]);
        }
    }
    void getleftMax(vector<int>&height,vector<int>&maxi)
    {
        int n=height.size();
        maxi[0]=height[0];
        for(int i=1;i<n;i++)
        {
            maxi[i]=max(maxi[i-1],height[i]);
        }
    }
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax(n,0);
        vector<int>rightMax(n,0);
        getleftMax(height,leftMax);
        getrightMax(height,rightMax);

        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(leftMax[i],rightMax[i])-height[i];
        }
        return ans;
    }
};