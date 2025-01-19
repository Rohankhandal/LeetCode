class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        
        int ans=0;
        int i=0;
        int a=num1,b=num2,c=num3;
        while(a || b|| c)
        {
            int A=a%10;
            int B=b%10;
            int C=c%10;
            int mini=min({A,B,C});
            cout<<mini;
            ans=ans+pow(10,i++)*mini;

            a/=10;
            b/=10;
            c/=10;
        }
        return ans;
    }
};