class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) {
        long long  xorVal=0;
        for(auto &num:arr)
        {
            xorVal^=num;
        }
        int n=arr.size();
        
        long long  firstRightSet=xorVal&(~(xorVal-1));
        // cout<<firstRightSet<<endl;
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(firstRightSet&arr[i]){
                a^=arr[i];
            }
            else
            {
                b^=arr[i];
            }
        }
        vector<int>ans{a,b};
        sort(ans.rbegin(),ans.rend());
        return ans;
    }
};