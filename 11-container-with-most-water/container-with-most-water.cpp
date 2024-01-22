class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxWater=0;
        while(left<right)
        {
            int minHeight=min(height[left],height[right]);
            int width=right-left;

            int area=minHeight*width;
           

        maxWater=max(maxWater,area);
            
            if(height[left]<= height[right])  //greedy appraoch to check maximum height
            {
                left++;
            }
            else
            {
                right--;
            }

            
            
        }

        return maxWater;
    }
};