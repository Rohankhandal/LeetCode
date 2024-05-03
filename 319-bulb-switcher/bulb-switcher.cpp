class Solution {
public:
    int bulbSwitch(int n) {
        //Observation
        int cnt=0;
        for(int i=1;i*i<=n;i++)
        {
            cnt++;
        }
        return cnt;  //or sqrt(n)
    }
};