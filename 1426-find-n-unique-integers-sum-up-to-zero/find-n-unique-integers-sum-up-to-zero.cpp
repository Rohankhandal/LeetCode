class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n&1){
            int half=n/2;
            for(int i=0;i<=half;i++){
                ans.push_back(i);
            }
            int cnt=0;
            int val=1;
            while(cnt<half){
                ans.push_back(-val);
                val++;
                cnt++;
            }
        }
        else{
            int half=n/2;
            for(int i=0;i<half;i++){
                ans.push_back(i+1);
            }
            int cnt=0;
            int val=1;
            while(cnt<half){
                ans.push_back(-val);
                val++;
                cnt++;
            }
        }
        return ans;
    }
};