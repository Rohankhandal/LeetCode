class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        int carry=0;
        for(int i=num.size()-1; i>=0 || k>0 ; i--){      //if nums=[0] and k=23 => output:-[2,3]
            int sum=0;
            if(i>=0){
               sum = num[i];
            }
            sum =  sum + carry + k%10;
            ans.push_back(sum%10);
            carry=sum/10;
            k/=10;
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> addToArrayForm(vector<int>& nums, int k) {
//         int n=nums.size();
//         int i=n-1;
//         int carry=0;
//         vector<int> ans;
//         while(i>=0)
//         {
//             int dig=k%10;
//             k/=10;
//             int sum=nums[i]+dig+carry;
//             ans.push_back(sum%10);
//             carry=sum/10;
            
//             i--;
//         }
//         while(k)   //if nums=[0] and k=23 => output:-[2,3]
//         {
//             int dig=k%10;
//             k/=10;
//             int sum=dig+carry;
//             ans.push_back(sum%10);
//             carry=sum/10;
//         }
//         if(carry>0)
//         {
//             ans.push_back(carry);
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };