class Solution {
public:
    int singleNumber(vector<int>& arr) {
        vector<int>bits(32,0);
        int n=arr.size();
        for(int i=0;i<32;i++){
            int cnt=0;
            for(auto &num:arr)
            {
                if((num>>i)&1)
                {
                    cnt++;
                }
            }
            
            bits[i]=cnt%3;
        }
        
        long long ans=0;
        long long power=1;
        for(int i=0;i<32;i++){
            if(bits[i])
                ans=ans+power;
            power*=2;
        }
        return ans;
    }
};