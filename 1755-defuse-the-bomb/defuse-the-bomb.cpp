class Solution {
public:
    void forward(vector<int>&code,int i,vector<int>&ans,int k)
    {
        int cnt=0;
        int sum=0;
        int n=code.size();
        while(cnt<k)
        {

            sum+=code[(i+1)%n];
            i++;
            cnt++;
        }
        ans.push_back(sum);

    }
    
    void backward(vector<int>&code,int i,vector<int>&ans,int k)
    {
        int cnt=0;
        int sum=0;
        int n=code.size();
        while(cnt<abs(k))
        {
            if(i==0) i=n;

            sum+=code[(i-1)%n];
            i--;
            cnt++;
        }
        ans.push_back(sum);

    }
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans;
        int n=code.size();

        for(int i=0;i<n;i++)
        {
            if(k>0) forward(code,i,ans,k);
            else if(k<0) backward(code,i,ans,k);
            else ans.push_back(0);
        }
        return ans;
    }
};