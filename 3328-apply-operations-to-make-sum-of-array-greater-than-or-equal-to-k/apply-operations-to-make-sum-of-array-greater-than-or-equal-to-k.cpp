class Solution {
public:
    int minOperations(int k) {
        int mini=INT_MAX;
        if(k==1) return 0;
        // for(int i=1;i<=k;i++)
        // {
        //      int minOp=0;
        //      minOp+=(k/i)+(k%i!=0);
        //      mini=min(minOp,mini);
        // }
        for(int i=2;i<=k;i++)
        {
             int minOp=0;
             minOp+=(i-1);
             minOp=minOp+(k/i)-(k%i==0);
             mini=min(minOp,mini);
        }
        return mini;
    }
};