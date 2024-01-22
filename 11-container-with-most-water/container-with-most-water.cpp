class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxi=0;
        while(left<=right)
        {
            int minHeight=min(height[left],height[right]);
            int width=right-left;
            int area=minHeight*width;
            cout<<"Area="<<area<<endl;

            maxi=max(maxi,area);
            cout<<"Maxi="<<maxi<<endl;
            if(height[left]<=height[right])
            {
                left++;
            }
            else
            {
                right--;
            }

            
            
        }

        return maxi;
    }
};