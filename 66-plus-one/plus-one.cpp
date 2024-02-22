class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;
        int i=n-1;
        while(carry&&i>=0)
        {
            int sum=digits[i]+carry;
            digits[i]=sum%10;
            carry=sum/10;

            i--;
        }
        if(carry)
        {
            vector<int>ans(n+1);
            ans[0]=carry;
            for(int i=1;i<n+1;i++)
            {
                ans[i]=digits[i-1];
            }
            return ans;
        }
        return digits;
    }
};