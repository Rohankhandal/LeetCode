class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        int carry=0;
        int sum=0;
       reverse(num.begin(),num.end());
        vector<int>ans;
        int i=0;
        while(k)
        {
            if(i!=n)
            {
                sum=num[i++]+(k%10)+carry;
                ans.emplace_back(sum%10);
                carry=sum/10;
                k/=10;
            }
            else{
                sum=(k%10)+carry;
                ans.emplace_back(sum%10);
                carry=sum/10;
                k/=10;
            }
        }
        while(carry)
        {
            if(i!=n)
            sum=num[i++]+carry;
            else
            sum=carry;
            ans.emplace_back(sum%10);
            carry=sum/10;
        }
        while(i!=n)
        {
            ans.emplace_back(num[i++]);
        }
        reverse(ans.begin(),ans.end());
        return ans;



        // for(int i=n-1;i>=0;i--)
        // {
        //     sum=num[i]+(k%10)+carry;
        //     k=k/10;
        //     carry=sum/10;
        //     num[i]=sum%10;
        // }
        // while()
        // vector<int>ans(n+1);
        // if(carry){
        //     ans[0]=carry;
        //     int i=1;
        //    for(auto &it:num)
        //    {
        //     ans[i++]=it;
        //    }
        //    return ans;
        // }
        // return num;
    }
};