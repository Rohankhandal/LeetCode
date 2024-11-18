class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans;
        int start=1,end=k;
        int sum=0;
        int n=code.size();
        if(k<0)
        {
            start=n-abs(k);
            end=n-1;
        }   
        
        for(int i=start;i<=end;i++)
        {
            sum+=code[i];
        }   
        ans.push_back(sum);

        for(int i=1;i<n;i++)
        {
            sum-=code[(start)%n];
            // cout<<sum<<" ";
            end++;
            sum+=code[end%n];
            // cout<<sum<<endl;
            start++;
            ans.push_back(sum);

        }
        return ans;
    }
};