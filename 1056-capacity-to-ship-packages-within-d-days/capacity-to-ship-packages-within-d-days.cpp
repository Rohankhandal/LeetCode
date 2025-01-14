class Solution {
public:
    bool isValid(vector<int>& weights, int days, int tar) {
    int cnt = 1; // Start with the first day
    int sum = 0;

    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] > tar) {
            return false; // If a single weight exceeds tar, it's invalid
        }
        if (sum + weights[i] <= tar) {
            sum += weights[i];
        } else {
            cnt++;        // Start a new day
            sum = weights[i]; // Reset sum to the current weight
        }
    }

    return (cnt <= days);
}

    int shipWithinDays(vector<int>& weights, int days) {
        int total=accumulate(weights.begin(),weights.end(),0);
        int l=1,r=total;
        int ans=0;
        int n=weights.size();
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(isValid(weights,days,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};